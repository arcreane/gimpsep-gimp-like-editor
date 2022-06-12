#include "../headers/effects/Erosion.h"

Erosion::Erosion(int size) {
    this->size = size;
}

cv::Mat Erosion::apply(Image image){
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * this->size + 1, 2 * this->size + 1));

    cv::Mat erosion;
    cv::erode(image.getMatrix(), erosion, kernel);
    return erosion;
}