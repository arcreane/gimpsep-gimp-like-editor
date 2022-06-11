#pragma once

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include "../models/UserAction.h"
#include "../models/FileName.h"
#include "../models/Effect.h"
#include "../models/Dilatation.h"

using namespace std;

/**
 * View of the GimpApplication
 */
class AppWindow{

    string title;

public:
    AppWindow(){
        this->title = "Gimp Like Image Editor";
        cv::namedWindow(title, cv::WINDOW_AUTOSIZE);
    }


    void renderView(const cv::Mat& image){
        cv::imshow(title, image);
        cout << "Press any key to display ACTIONS menu" << endl;
        cv::waitKey(0);
    }

    /**
     * Display a message when the GimpApplication is intanciated
     */
    static void displayWelcomeMessage() {
        cout << "\n" << endl;
        cout << "**************************************************" << endl;
        cout << "------------ WELCOME TO GIMP FORK ----------------" << endl;
        cout << "**************************************************" << endl;
        cout << "\n" << endl;
    }

    /**
     * Display a message when the GimpApplication is destroyed
     */
    static void displayExitMessage() {
        cout << "\n" << endl;
        cout << "**************************************************" << endl;
        cout << "------------ THANKS FOR USING GIMP FORK ----------" << endl;
        cout << "--------------------- GOOD BYE -------------------" << endl;
        cout << "**************************************************" << endl;
        cout << "\n" << endl;
    }

    /**
     * Asks the Action that the user wants to perform on the loaded image
     * @return action name
     */
    static string askForActionName() {
        int userChoice = 0;

        cout << "\n" << endl;
        cout << "---------- SELECT AN ACTION --------------" << endl;

        for(const auto& [key, value]: UserAction::actions){
            cout << key << " = " << value << endl;
        }

        int maxChoiceIndex = UserAction::getNumberOfAvailableActions()-1;

        while(userChoice < -1 || userChoice > maxChoiceIndex || userChoice == 0 ){
            cout << "Enter your choice [0-" << maxChoiceIndex << "] : ";
            cin >> userChoice;
        }

        return UserAction::getActionName(userChoice);
    }

    /**
     * Create an instance of the Effect corresponding to the requested action
     * @param actionIndex : index in Action Enum of the requested Action
     * @return effect : Effect object with parameter to compute the desired action
     */
    static Effect* getEffectInstanceWithParameters(string actionName){
        Effect* effect;

        if(actionName == "DILATATION"){
            int size = 0;
            cout << "Choose dilatation size :" << endl;
            cin >> size;
            effect = new Dilatation(size);
        }else if(actionName == "EROSION"){
            int size = 0;
            cout << "Choose erosion size :" << endl;
            cin >> size;
            effect = new Dilatation(size);
        }else{
            effect = nullptr;
        }

        return effect;
    }

    string askForFileName() {
        int userChoice = 0;

        cout << "\n" << endl;
        cout << "---------- SELECT A FILE --------------" << endl;

        for(const auto& [key, value]: FileName::files){
            cout << key << " = " << value << endl;
        }

        int maxChoiceIndex = FileName::getNumberOfAvailableFiles();

        while(userChoice <= 0 || userChoice > maxChoiceIndex){
            cout << "Enter your choice [0-" << maxChoiceIndex << "] : ";
            cin >> userChoice;
        }

        return FileName::getFileName(userChoice);
    }
};