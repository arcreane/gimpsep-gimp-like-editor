#pragma once
#include <iostream>
#include <string>
#include "../observer/Subject.h"
#include "../models/Effect.h"

using namespace std;

class AppController : public Subject{

public:

    void applyEffect(Image image, Effect* effect){
        preChangeNotification();

        cv::Mat newMatrix = effect->apply(image);
        Image modifiedImage("Modified image", newMatrix);

        afterChangeNotification(modifiedImage, "");
    }

    void performSpecialAction(string action){
        afterChangeNotification({}, action);
    }

};