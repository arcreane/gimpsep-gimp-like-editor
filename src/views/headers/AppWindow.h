#pragma once

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "../../models/headers/UserAction.h"
#include "../../models/headers/FileName.h"
#include "../../models/headers/Effect.h"
#include "../../models/headers/Dilatation.h"
#include "../../models/headers/Erosion.h"

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
        static string  askForActionName();

        /**
         * Create an instance of the Effect corresponding to the requested action
         * @param actionIndex : index in Action Enum of the requested Action
         * @return effect : Effect object with parameter to compute the desired action
         */
        static Effect* getEffectInstanceWithParameters(string actionName);
        string         askForFileName();
};