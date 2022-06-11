#include <iostream>

#include "Observer.h"
#include "../../models/headers/Image.h"
#include "../../models/headers/UserAction.h"

#pragma once

using namespace std;

class Subject {
    private:
        vector<Observer*> observers;

    public:
        virtual ~Subject() = default;

        void attach(Observer& o);
        void detach(Observer& o);
        void preChangeNotification();
        void afterChangeNotification(Image image, action_e specialAction);
};