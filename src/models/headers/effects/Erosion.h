#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include "../Effect.h"
#include "../Image.h"

using namespace std;

class Erosion : public Effect {
private:
    int size;

public:

    Erosion(int size);

    cv::Mat apply(Image image);
};
