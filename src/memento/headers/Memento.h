#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include "../../models/headers/Image.h"

class Memento {
    public:
        virtual std::string getName() const = 0;
        virtual std::string date() const = 0;
        virtual Image       getState() const = 0;
};