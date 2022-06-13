#include "headers/AppController.h"

AppController::AppController() {}

void AppController::applyEffect(Image image, Effect* effect){
    preChangeNotification();

    cv::Mat newMatrix   = effect->apply(image);
    string title        = image.getTitle();

    Image modifiedImage(title, newMatrix);
    afterChangeNotification(modifiedImage, ACTION_MAX);
}

void AppController::performSpecialAction(action_e action){
    afterChangeNotification({}, action);
}

void AppController::saveImage(Image image, string destinationPath){
    string imageName    = image.getTitle();
    string fullPath     = destinationPath + imageName;
    cout << "Fullpath : " << fullPath << endl;
    cv::imwrite(fullPath, image.getMatrix());
}