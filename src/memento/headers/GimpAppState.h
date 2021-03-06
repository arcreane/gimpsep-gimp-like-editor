#pragma once

#include <iostream>

#include "Memento.h"
#include "../../models/headers/Image.h"

using namespace std;

class GimpAppState : public Memento {
    private:
        string name;
        Image  state;
        string date_;

    public:
        GimpAppState(Image state, string name);

        /**
         * The Originator uses this method when restoring its state.
         */
        Image  getState() const override;
        string getName() const override;
        string date() const override;
};