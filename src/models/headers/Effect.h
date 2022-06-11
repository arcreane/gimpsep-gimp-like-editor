#pragma once

#include <opencv2/opencv.hpp>
#include "Image.h"

using namespace std;

class Effect {
    public:
        virtual cv::Mat apply(Image image) = 0;
};