#include "headers/Blur.h"

Blur::Blur(int kernelSize) {
    this->kernelSize = kernelSize;
}

cv::Mat Blur::apply(Image image) {
    cout << "APPLY blur on " << image.getTitle() << endl;

    cv::Mat blur;

    cv::blur(image.getMatrix(), blur, cv::Size(this->kernelSize, this->kernelSize));
    return blur;
}