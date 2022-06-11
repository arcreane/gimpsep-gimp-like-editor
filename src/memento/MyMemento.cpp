#include "headers/MyMemento.h"

MyMemento::MyMemento(Image state, std::string name) {
    std::time_t now = std::time(0);
    this->state = state;
    this->name  = name;
    this->date_ = std::ctime(&now);
}

Image MyMemento::getState() const {
    return this->state;
}

string MyMemento::getName() const {
    return this->name;
}

string MyMemento::date() const {
    return this->date_;
}