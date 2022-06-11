#include "headers/GimpAppState.h"

GimpAppState::GimpAppState(Image state, std::string name) {
    std::time_t now = std::time(0);
    this->state = state;
    this->name  = name;
    this->date_ = std::ctime(&now);
}

Image GimpAppState::getState() const {
    return this->state;
}

string GimpAppState::getName() const {
    return this->name;
}

string GimpAppState::date() const {
    return this->date_;
}