#include "headers/Contrast.h"

Contrast::Contrast(float contrastValue) {
    this->contrastValue = contrastValue;
}

cv::Mat Contrast::apply(Image image){
    cout << "APPLY contrast on " << image.getTitle() << endl;

    cv::Mat contrast;
    image.getMatrix().convertTo(contrast, -1, contrastValue, 0);

    return contrast;
}