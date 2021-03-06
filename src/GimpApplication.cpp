#include "GimpApplication.h"

#include "memento/headers/GimpAppState.h"
#include "models/headers/UserAction.h"

GimpApplication::GimpApplication(AppController& s) : subjectController(s) {
        subjectController.attach(*this);
        this->onLoad();
}

GimpApplication::~GimpApplication(){
    subjectController.detach(*this);
}

void GimpApplication::beforeChangeUpdate(Subject& changedSubject) {
    return;
}

void GimpApplication::afterChangeUpdate(Subject& changedSubject, Image image, action_e specialAction) {
    if(&changedSubject != &subjectController){
        return;
    }

    if(specialAction > 0 && specialAction < ACTION_MAX){
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
void GimpApplication::onLoad(){
    windowView.displayWelcomeMessage();
}

/**
 * Main loop to ask action to user and to apply those actions while the user is not requesting Application EXIT
 */
void GimpApplication::run() {
    bool isRunning = true;
    action_e userRequestedAction;
    string imagePath = windowView.askForFileName();
    this->afterChangeUpdate(subjectController, Image(imagePath), ACTION_MAX);

    while(isRunning){
        userRequestedAction = AppWindow::askForAction();

        if(USER_WANTS_TO_EXIT(userRequestedAction)){
            isRunning = false;
        }else if(USER_ASK_FOR_SAVING_CHANGES(userRequestedAction)){
            subjectController.saveImage(this->state, saveDestination);
        }else if(USER_ASK_FOR_STATE_CHANGING(userRequestedAction)){
            subjectController.performSpecialAction(userRequestedAction);
        }else{
            lastAppliedEffect = userRequestedAction;
            Effect* effect = AppWindow::getEffectInstanceWithParameters(userRequestedAction);
            subjectController.applyEffect(state, effect);
        }
    }

    AppWindow::displayExitMessage();
}

/**
 * Calls the renderView function with a new Image Matrix to display
 */
void GimpApplication::updateView() {
    windowView.renderView(state.getMatrix());
}

/**
* Method used by the Memento Pattern and called by the Caretaker to store states in its memory
* @return
*/
Memento * GimpApplication::save() {
    return new GimpAppState(this->state, actionNames[this->lastAppliedEffect]);
}

/**
 * Method used by the Memento Pattern and called by the Caretaker when the User requests a undo()
 * @param memento
 */
void GimpApplication::restore(Memento *memento) {
    this->state = memento->getState();
    this->updateView();
}