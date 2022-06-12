#include "../headers/effects/Rotate.h"

Rotate::Rotate(double angle) {
    this->angle = angle;
}

cv::Mat Rotate::apply(Image image) {

    cv::Mat rotatedImage;

    cv::Point2f center(image.getMatrix().cols/2,image.getMatrix().rows/2);
    cv::Mat rotationMatrix = getRotationMatrix2D(center,this->angle,1);

    warpAffine(image.getMatrix(),rotatedImage,rotationMatrix, cv::Size());
    return rotatedImage;
}
