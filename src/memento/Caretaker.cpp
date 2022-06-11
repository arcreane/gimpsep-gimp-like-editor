#include "headers/Caretaker.h"

#include "../models/headers/UserAction.h"

Caretaker::Caretaker(AppController& subjectController, GimpApplication* gimpApplication): subjectController(subjectController), gimpApplication(gimpApplication) {
    subjectController.attach(*this);
    //this->gimpApplication = gimpApplication;
}

Caretaker::~Caretaker() {
    subjectController.detach(*this);
}

void Caretaker::beforeChangeUpdate(Subject& changedSubject) {
    if(&changedSubject != &subjectController){
        return;
    }

    this->backup();
}

void Caretaker::afterChangeUpdate(Subject& changedSubject, Image image, action_e specialAction) {
    if(&changedSubject != &subjectController){
        return;
    }

    if(specialAction > 0 && specialAction < ACTION_MAX) {
        if(specialAction == ACTION_HISTORY) {
            this->showHistory();
        } else if (specialAction == ACTION_UNDO) {
            this->undo();
        }

        return;
    }
}

void Caretaker::backup() {
    this->mementos_.push_back(this->gimpApplication->save());
}

void Caretaker::undo() {
    if (!this->mementos_.size()) {
        std::cout << "No previous state to restore\n" << endl;
        return;
    }

    Memento *memento = this->mementos_.back();
    this->mementos_.pop_back();
    std::cout << "Restoring state to: " << memento->getState().getTitle() << "\n";

    try {
        this->gimpApplication->restore(memento);
    } catch(...) {
        this->undo();
    }
}

void Caretaker::showHistory() const {
    cout << "\n" << endl;
    cout << "This is the list of applied effects :\n";
    for(Memento *memento : this->mementos_) {
        cout <<memento->getName()  << "\n";
    }
}