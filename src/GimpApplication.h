#pragma once
#include <iostream>
#include <string>
#include "observer/Observer.h"
#include "controllers/AppController.h"
#include "views/AppWindow.h"
#include "memento/Memento.h"
#include "memento/MyMemento.h"

using namespace std;

class GimpApplication : public Observer{

    AppController&  subjectController;
    AppWindow       windowView;
    Image           state;
    string          lastAppliedEffect;

public:

    /**
     * Constructor used to map the GimpApplication with the Observer pattern on the AppController
     * @param s : AppController to subscribe to
     */
    explicit GimpApplication(AppController& s) : subjectController(s) {
        subjectController.attach(*this);
        this->onLoad();
    }

    ~GimpApplication(){
        subjectController.detach(*this);
    }

    void beforeChangeUpdate(Subject& changedSubject) override{
        return;
    }

    void afterChangeUpdate(Subject& changedSubject, Image image, string specialAction) override{
        if(&changedSubject != &subjectController){
            return;
        }
        if(!specialAction.empty()){
            //undo is handled with the Memento pattern
            //History doesn't need state update
            return;
        }
        this->state = image;
        updateView();
    }

    /**
     * Runs when the class is instanciated to inform the User
     */
    void onLoad(){
        windowView.displayWelcomeMessage();
    }

    /**
     * Main loop to ask action to user and to apply those actions while the user is not requesting Application EXIT
     */
    void run(){
        bool isRunning = true;
        string userRequestedActionName;
        string imagePath = windowView.askForFileName();
        this->afterChangeUpdate(subjectController, Image(imagePath), "");

        while(isRunning){
            userRequestedActionName         = windowView.askForActionName();
            bool userWantsToExit            = (userRequestedActionName == UserAction::getExitAction());
            bool userAsksForStateChanging   = (userRequestedActionName == UserAction::getHistoryAction() || userRequestedActionName == UserAction::getUndoAction());

            if(userWantsToExit){
                isRunning = false;
            }else if(userAsksForStateChanging){
                subjectController.performSpecialAction(userRequestedActionName);
            }else{
                lastAppliedEffect = userRequestedActionName;
                Effect* effect = windowView.getEffectInstanceWithParameters(userRequestedActionName);
                subjectController.applyEffect(state, effect);
            }
        }
        windowView.displayExitMessage();
    }

    /**
     * Calls the renderView function with a new Image Matrix to display
     */
    void updateView(){
        windowView.renderView(state.getMatrix());
    }

    /**
    * Method used by the Memento Pattern and called by the Caretaker to store states in its memory
    * @return
    */
    Memento *save() {
        return new MyMemento(this->state, this->lastAppliedEffect);
    }

    /**
     * Method used by the Memento Pattern and called by the Caretaker when the User requests a undo()
     * @param memento
     */
    void restore(Memento *memento) {
        this->state = memento->getState();
        this->updateView();
    }

};
