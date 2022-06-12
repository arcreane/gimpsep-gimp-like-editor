#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include "../Effect.h"
#include "../Image.h"

using namespace std;

class Stitching : public Effect {
    public:
        Stitching();

        cv::Mat apply(Image image);
};