#include "headers/AppWindow.h"

#include "../models/headers/effects/Dilatation.h"
#include "../models/headers/effects/Erosion.h"
#include "../models/headers/effects/Brightness.h"
#include "../models/headers/effects/Blur.h"
#include "../models/headers/effects/Gray.h"
#include "../models/headers/effects/Rotate.h"
#include "../models/headers/effects/Stitching.h"
#include "../models/headers/effects/EdgeDetection.h"
#include "../models/headers/effects/Resize.h"
#include "../models/headers/effects/Crop.h"
#include "../models/headers/effects/Contrast.h"
#include "../models/headers/FileName.h"

AppWindow::AppWindow() {
    this->title = "Gimp Like Image Editor";
    cv::namedWindow(title, cv::WINDOW_AUTOSIZE);
}


void AppWindow::renderView(const cv::Mat& image) {
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
action_e AppWindow::askForAction() {
    int userChoice = -1;
    int i;

    cout << "\n" << endl;
    cout << "---------- SELECT AN ACTION --------------" << endl;

    for(i=0 ; i<ACTION_MAX ; i++) {
        cout << i << " = " << actionNames[i] << endl;
    }

    while(userChoice < 0 || userChoice >= ACTION_MAX){
        cout << "Enter your choice [0-" << ACTION_MAX << "] : ";
        cin >> userChoice;
    }

    return (action_e) userChoice;
}

/**
 * Create an instance of the Effect corresponding to the requested action
 * @param actionIndex : index in Action Enum of the requested Action
 * @return effect : Effect object with parameter to compute the desired action
 */
Effect* AppWindow::getEffectInstanceWithParameters(action_e action) {
    Effect* effect;

    if(action == ACTION_DILATATION) {
        Dilatation* dilatation = new Dilatation();
        dilatation->setParametersFromUserInput();
        effect = dilatation;
    } else if(action == ACTION_EROSION) {
        int size = 0;
        cout << "Choose erosion size :" << endl;
        cin >> size;
        effect = new Erosion(size);
    } else if(action == ACTION_CONTRAST) {
        float contrastValue = -1;
        cout << "Choose contrast value (> 0) :" << endl;

        while(contrastValue < 0) {
            cin >> contrastValue;
        }

        effect = new Contrast(contrastValue);
    } else if(action == ACTION_CROP) {
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
    } else if(action == ACTION_RESIZING) {
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
    } else if(action == ACTION_EDGE_DETECTION) {
        effect = new EdgeDetection();
    } else if(action == ACTION_BLUR) {
        int kernelSize;
        cout << "Choose kernel size :" << endl;
        cin >> kernelSize;
        effect = new Blur(kernelSize);
    } else if(action == ACTION_CONVERT_TO_GREY) {
        effect = new Gray();
    } else if(action == ACTION_ROTATE) {
        double angle;
        cout << "Choose rotation angle :" << endl;
        cin >> angle;
        effect = new Rotate(angle);
    } else if(action == ACTION_STITCHING) {
        effect = new Stitching();
    } else if(action == ACTION_BRIGHTNESS) {
        int factor = -201;

        while(factor<-200 || factor>200){
            cout << "Enter an brightness factor [-200; 200] :" << endl;
            cin >> factor;
        }

        effect = new Brightness(factor);
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