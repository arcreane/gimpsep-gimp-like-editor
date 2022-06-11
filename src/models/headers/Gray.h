#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Effect.h"
#include "Image.h"


using namespace std;

class Gray : public Effect{
    public:
        Gray();
        cv::Mat apply(Image image);
};
