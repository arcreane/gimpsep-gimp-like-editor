#include <opencv2/core/mat.hpp>
#include "../headers/effects/Brightness.h"

Brightness::Brightness(int factor) {
    this->factor = factor;
}

cv::Mat Brightness::apply(Image image){
    cv::Mat imageWithChangedBrightness = cv::Mat::zeros(image.getMatrix().size(), image.getMatrix().type());
    image.getMatrix().cv::Mat::convertTo(imageWithChangedBrightness, -1, 1, this->factor );
    return imageWithChangedBrightness;
}