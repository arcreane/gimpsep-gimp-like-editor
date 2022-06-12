#include "../headers/effects/Blur.h"

Blur::Blur(int kernelSize) {
    this->kernelSize = kernelSize;
}

cv::Mat Blur::apply(Image image) {

    cv::Mat blur;

    cv::blur(image.getMatrix(), blur, cv::Size(this->kernelSize, this->kernelSize));
    return blur;
}