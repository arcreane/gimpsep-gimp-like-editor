#include "headers/Subject.h"

void Subject::attach(Observer& o) {
    observers.push_back(&o);
}

void Subject::detach(Observer& o) {
    observers.erase(remove(observers.begin(), observers.end(), &o));
}


void Subject::preChangeNotification() {
    for(auto* observer : observers){
        observer->beforeChangeUpdate(*this);
    }
}

void Subject::afterChangeNotification(Image image, string specialAction) {
    for(auto* observer : observers){
        observer->afterChangeUpdate(*this, image, specialAction);
    }
}