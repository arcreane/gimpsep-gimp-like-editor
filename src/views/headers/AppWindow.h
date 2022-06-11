#pragma once

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

#include "../../models/headers/UserAction.h"
#include "../../models/headers/Effect.h"

using namespace std;

/**
 * View of the GimpApplication
 */
class AppWindow {
    private:
        string title;

    public:
        AppWindow();

        void           renderView(const cv::Mat& image);

        /**
         * Display a message when the GimpApplication is intanciated
         */
        static void    displayWelcomeMessage();

        /**
         * Display a message when the GimpApplication is destroyed
         */
        static void    displayExitMessage();

        /**
         * Asks the Action that the user wants to perform on the loaded image
         * @return action name
         */
        static action_e askForAction();

        /**
         * Create an instance of the Effect corresponding to the requested action
         * @param actionIndex : index in Action Enum of the requested Action
         * @return effect : Effect object with parameter to compute the desired action
         */
        static Effect* getEffectInstanceWithParameters(action_e action);
        string         askForFileName();
};