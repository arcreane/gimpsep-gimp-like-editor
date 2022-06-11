#include "headers/AppController.h"

AppController::AppController() {}

void AppController::applyEffect(Image image, Effect* effect){
    preChangeNotification();

    cv::Mat newMatrix = effect->apply(image);
    Image modifiedImage("Modified image", newMatrix);

    afterChangeNotification(modifiedImage, ACTION_MAX);
}

void AppController::performSpecialAction(action_e action){
    afterChangeNotification({}, action);
}