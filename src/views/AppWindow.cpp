#include "headers/AppWindow.h"

#include "../models/headers/Dilatation.h"
#include "../models/headers/Blur.h"
#include "../models/headers/Gray.h"
#include "../models/headers/Rotate.h"
#include "../models/headers/Stitching.h"
#include "../models/headers/EdgeDetection.h"
#include "../models/headers/Resize.h"
#include "../models/headers/Crop.h"
#include "../models/headers/Contrast.h"
#include "../models/headers/UserAction.h"
#include "../models/headers/FileName.h"

AppWindow::AppWindow() {
    this->title = "Gimp Like Image Editor";
    cv::namedWindow(title, cv::WINDOW_AUTOSIZE);
}


void AppWindow::renderView(const cv::Mat& image){
    cv::imshow(title, image);
    cout << "Press any key to display ACTIONS menu" << endl;
    cv::waitKey(0);
}

/**
 * Display a message when the GimpApplication is intanciated
 */
void AppWindow::displayWelcomeMessage() {
    cout << "\n" << endl;
    cout << "**************************************************" << endl;
    cout << "------------ WELCOME TO GIMP FORK ----------------" << endl;
    cout << "**************************************************" << endl;
    cout << "\n" << endl;
}

/**
 * Display a message when the GimpApplication is destroyed
 */
void AppWindow::displayExitMessage() {
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
string AppWindow::askForActionName() {
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
Effect* AppWindow::getEffectInstanceWithParameters(string actionName){
    Effect* effect;

    if(actionName == "DILATATION") {
        int size = 0;
        cout << "Choose dilatation size :" << endl;
        cin >> size;
        effect = new Dilatation(size);
    } else if(actionName == "EROSION") {
        int size = 0;
        cout << "Choose erosion size :" << endl;
        cin >> size;
        effect = new Erosion(size);
    } else if(actionName == "CONTRAST") {
        float contrastValue = -1;
        cout << "Choose contrast value (> 0) :" << endl;

        while(contrastValue < 0) {
            cin >> contrastValue;
        }

        effect = new Contrast(contrastValue);
    } else if(actionName == "CROP") {
        int startColumn = -1;
        int endColumn = -1;
        int startRow = -1;
        int endRow = -1;

        cout << "Choose start position (x > 0, y > 0) :" << endl;

        while(startColumn < 0) {
            cout << "\tx : ";
            cin >> startColumn;
        }

        while(endColumn < 0) {
            cout << "\ty : ";
            cin >> endColumn;
        }

        cout << "Choose end position (x, y) :" << endl;

        while(startRow < 0) {
            cout << "\tx : ";
            cin >> startRow;
        }

        while(endRow < 0) {
            cout << "\ty : ";
            cin >> endRow;
        }

        effect = new Crop(startColumn, startRow, endColumn, endRow);
    } else if(actionName == "RESIZING") {
        int option = -1;

        while(option <= 0 || option > 2) {
            cout << "Choose resizing option :" << endl;
            cout << "1 = WIDTH & HEIGHT" << endl;
            cout << "2 = SCALE FACTORS" << endl;
            cin >> option;
        }

        if(option == 1) {
            int width = 0;
            int height = 0;

            while (width < 1) {
                cout << "New width : ";
                cin >> width;
            }

            while (height < 1) {
                cout << "New height : ";
                cin >> height;
            }

            effect = new Resize(width, height);
        } else {
            double scaleX = 0;
            double scaleY = 0;

            while(scaleX <= 0) {
                cout << "scale factor for X : ";
                cin >> scaleX;
            }

            while (scaleY <= 0) {
                cout << "Scale factor for Y : ";
                cin >> scaleY;
            }

            effect = new Resize(scaleX, scaleY);
        }
    } else if(actionName == "EDGE DETECTION") {
        effect = new EdgeDetection();
    } else if(actionName == "BLUR") {
        int kernelSize;
        cout << "Choose kernel size :" << endl;
        cin >> kernelSize;
        effect = new Blur(kernelSize);
    } else if(actionName == "CONVERT TO GREY") {
        effect = new Gray();
    } else if(actionName == "ROTATE") {
        double angle;
        cout << "Choose rotation angle :" << endl;
        cin >> angle;
        effect = new Rotate(angle);
    } else if(actionName == "STITCHING") {
        effect = new Stitching();
    } else {
            effect = nullptr;
    }

    return effect;
}

string AppWindow::askForFileName() {
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