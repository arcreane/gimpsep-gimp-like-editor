#pragma once
#include <iostream>
#include "Memento.h"
#include "../models/Image.h"


class MyMemento : public Memento {
private:
    std::string name;
    Image       state;
    std::string date_;

public:
    MyMemento(Image state, std::string name) : state(state) {
        std::time_t now = std::time(0);
        this->name  = name;
        this->date_ = std::ctime(&now);
    }

    /**
     * The Originator uses this method when restoring its state.
     */
    Image getState() const override {
        return this->state;
    }

    std::string getName() const override{
        return this->name;
    }

    std::string date() const override {
        return this->date_;
    }
};