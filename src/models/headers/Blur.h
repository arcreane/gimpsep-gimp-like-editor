#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Effect.h"
#include "Image.h"

using namespace std;

class Blur : public Effect{
    private:
        int kernelSize;

    public:
        Blur(int kernelSize);
        cv::Mat apply(Image image);
};
