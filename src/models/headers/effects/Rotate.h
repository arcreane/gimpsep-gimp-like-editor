#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include "../Effect.h"
#include "../Image.h"

using namespace std;

class Rotate : public Effect{
    private:
        double angle;

    public:
        Rotate(double angle);
        cv::Mat apply(Image image);
};
