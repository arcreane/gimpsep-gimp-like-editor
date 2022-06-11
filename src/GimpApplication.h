#pragma once
#include <iostream>
#include <string>
#include "observer/headers/Observer.h"
#include "controllers/headers/AppController.h"
#include "views/headers/AppWindow.h"
#include "memento/headers/Memento.h"
#include "memento/headers/MyMemento.h"

using namespace std;

class GimpApplication : public Observer{
private:
    AppController&  subjectController;
    AppWindow       windowView;
    Image           state;
    string          lastAppliedEffect;

public:
    /**
     * Constructor used to map the GimpApplication with the Observer pattern on the AppController
     * @param s : AppController to subscribe to
     */
    explicit GimpApplication(AppController& s);
    ~GimpApplication();

    void beforeChangeUpdate(Subject& changedSubject) override;
    void afterChangeUpdate(Subject& changedSubject, Image image, string specialAction) override;

    /**
     * Runs when the class is instanciated to inform the User
     */
    void onLoad();

    /**
     * Main loop to ask action to user and to apply those actions while the user is not requesting Application EXIT
     */
    void run();

    /**
     * Calls the renderView function with a new Image Matrix to display
     */
    void updateView();

    /**
    * Method used by the Memento Pattern and called by the Caretaker to store states in its memory
    * @return
    */
    Memento *save();

    /**
     * Method used by the Memento Pattern and called by the Caretaker when the User requests a undo()
     * @param memento
     */
    void restore(Memento *memento);
};
