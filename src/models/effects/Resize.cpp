#include "../headers/effects/Resize.h"

Resize::Resize(double scaleX, double scaleY) : scaleX(scaleX), scaleY(scaleY) {
    width = -1;
    height = -1;
}

Resize::Resize(int width, int height) : width(width), height(height) {}

cv::Mat Resize::apply(Image image) {
    cv::Mat resize;

    if(width > 0 && height > 0) {
        scaleX = (double) width / image.getMatrix().cols;
        scaleY = (double) height / image.getMatrix().rows;
    }

    cv::resize(image.getMatrix(), resize, cv::Size(), scaleX, scaleY, cv::INTER_LINEAR);

    return resize;
}
