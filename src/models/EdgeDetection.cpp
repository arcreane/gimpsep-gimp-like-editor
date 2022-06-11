//
// Created by Lou Rostan on 11/06/2022.
//

#include "headers/EdgeDetection.h"

EdgeDetection::EdgeDetection() {}

cv::Mat EdgeDetection::apply(Image image) {
    cv::Mat grayImage;
    cv::Mat blurredImage;
    cv::Mat edgesImage;

    cv::cvtColor(image.getMatrix(), grayImage, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(grayImage, blurredImage, cv::Size(3, 3), 0);
    cv::Canny(blurredImage, edgesImage, 100, 200, 3, false);

    return edgesImage;
}
