#pragma once

#include <iostream>
#include <opencv2/opencv.hpp>

#include "Effect.h"
#include "Image.h"

using namespace std;

class Brightness : public Effect {
private:
    int factor;

public:

    Brightness(int factor);

    cv::Mat apply(Image image);
};
