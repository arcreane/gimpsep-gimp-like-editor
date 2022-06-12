#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

#include "../Effect.h"
#include "../Image.h"

using namespace std;

class Dilatation : public Effect {
    private:
        int size;

    public:
        static const int MIN_SIZE = 2;
        static const int MAX_SIZE = 10;
        cv::Mat apply(Image image);
        void setParametersFromUserInput();
};
