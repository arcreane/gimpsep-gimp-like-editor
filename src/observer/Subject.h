#include <iostream>
#include "Observer.h"
#include "../models/Image.h"

#pragma once

class Subject{

    std::vector<Observer*> observers;

public:

    virtual ~Subject() = default;

    void attach(Observer& o){
        observers.push_back(&o);
    }

    void detach(Observer& o){
        observers.erase(std::remove(observers.begin(), observers.end(), &o));
    }


    void preChangeNotification(){
        for(auto* observer : observers){
            observer->beforeChangeUpdate(*this);
        }
    }

    void afterChangeNotification(Image image, string specialAction){
        for(auto* observer : observers){
            observer->afterChangeUpdate(*this, image, specialAction);
        }
    }
};