#include "headers/Caretaker.h"

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

void Caretaker::afterChangeUpdate(Subject& changedSubject, Image image, string specialAction) {
    if(&changedSubject != &subjectController){
        return;
    }

    if(!specialAction.empty()) {
        if(specialAction == UserAction::getHistoryAction()) {
            this->showHistory();
        } else if (specialAction == UserAction::getUndoAction()) {
            this->undo();
        }

        return;
    }
}

void Caretaker::backup() {
    std::cout << "\nCaretaker: Saving Originator's state...\n";
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