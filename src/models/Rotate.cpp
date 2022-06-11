#include "headers/Rotate.h"

Rotate::Rotate(double angle) {
    this->angle = angle;
}

cv::Mat Rotate::apply(Image image) {
    cout << "APPLY Rotate on " << image.getTitle() << endl;

    cv::Mat rotatedImage;

    cv::Point2f center(image.getMatrix().cols/2,image.getMatrix().rows/2);
    cv::Mat rotationMatrix = getRotationMatrix2D(center,this->angle = angle,1);

    warpAffine(image.getMatrix(),rotatedImage,rotationMatrix, cv::Size());
    return rotatedImage;
}
