#pragma once
#include <iostream>
#include <string>
#include "../../observer/headers/Subject.h"
#include "../../models/headers/Effect.h"

using namespace std;

class AppController : public Subject {
    public:
        AppController();

        void applyEffect(Image image, Effect* effect);
        void performSpecialAction(string action);
};