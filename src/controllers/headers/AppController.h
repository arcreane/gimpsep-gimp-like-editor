#pragma once

#include <iostream>
#include <string>

#include "../../observer/headers/Subject.h"
#include "../../models/headers/Effect.h"
#include "../../models/headers/UserAction.h"

using namespace std;

class AppController : public Subject {
    public:
        AppController();

        void applyEffect(Image image, Effect* effect);
        void performSpecialAction(action_e action);
        void saveImage(Image image, string destinationPath);
};