#pragma once

#include <iostream>
#include <vector>

#include "../../observer/headers/Observer.h"
#include "../../controllers/headers/AppController.h"
#include "../../GimpApplication.h"
#include "../../models/headers/Image.h"
#include "Memento.h"

class Caretaker : public Observer {
    private:
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
        explicit Caretaker(AppController& subjectController, GimpApplication* gimpApplication);
        ~Caretaker() override;

        void beforeChangeUpdate(Subject& changedSubject) override;
        void afterChangeUpdate(Subject& changedSubject, Image image, action_e specialAction) override;

        /**
         * Method that extract a memento from the Originator and save the states from
         */
        void backup();

        /**
         * Method that call the restore method of the originator with a memento
         */
        void undo();

        /**
         * Shows the list of stored state of the Originator
         */
        void showHistory() const;
};
