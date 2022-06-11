#pragma once
#include <iostream>
#include "../observer/Observer.h"
#include "../controllers/AppController.h"
#include <vector>
#include "Memento.h"
#include "../GimpApplication.h"

class Caretaker : public Observer {

    AppController&          subjectController;
    GimpApplication*        gimpApplication;
    std::vector<Memento *>  mementos_;

public:

    /**
     * Constructor used for both Memento Pattern and Observer Pattern.
     * Memento pattern on the instance of GimpApplication to stores all states changes
     * Observer pattern on the instance of AppController to call the back for each state change
     * @param subjectController : appController which we need to attach to
     * @param gimpApplication  :  gimpApplication that we need to save states from
     */
    explicit Caretaker(AppController& subjectController, GimpApplication* gimpApplication): subjectController(subjectController), gimpApplication(gimpApplication){
        subjectController.attach(*this);
        this->gimpApplication = gimpApplication;
    }


    ~Caretaker(){
        subjectController.detach(*this);
    }

    void beforeChangeUpdate(Subject& changedSubject) override{
        if(&changedSubject != &subjectController){
            return;
        }
        this->backup();
    }

    void afterChangeUpdate(Subject& changedSubject, Image image, string specialAction) override{
        if(&changedSubject != &subjectController){
            return;
        }
        if(!specialAction.empty()) {
            if (specialAction == UserAction::getHistoryAction()) {
                this->showHistory();
            } else if (specialAction == UserAction::getUndoAction()) {
                this->undo();
            }
            return;
        }
    }

    /**
     * Method that extract a memento from the Originator and save the states from
     */
    void backup() {
        std::cout << "\nCaretaker: Saving Originator's state...\n";
        this->mementos_.push_back(this->gimpApplication->save());
    }

    /**
     * Method that call the restore method of the originator with a memento
     */
    void undo() {
        if (!this->mementos_.size()) {
            std::cout << "No previous state to restore\n" << endl;
            return;
        }
        Memento *memento = this->mementos_.back();
        this->mementos_.pop_back();
        std::cout << "Restoring state to: " << memento->getState().getTitle() << "\n";
        try {
            this->gimpApplication->restore(memento);
        } catch (...) {
            this->undo();
        }
    }

    /**
     * Shows the list of stored state of the Originator
     */
    void showHistory() const {
        cout << "\n" << endl;
        cout << "This is the list of applied effects :\n";
        for (Memento *memento : this->mementos_) {
            cout <<memento->getName()  << "\n";
        }
    }

};
