#include "headers/Dilatation.h"

Dilatation::Dilatation(int size) {
    this->size = size;
}

cv::Mat Dilatation::apply(Image image){
    cout << "APPLY dilatation on " << image.getTitle() << endl;

    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * this->size + 1, 2 * this->size + 1));

    cv::Mat dilatation;
    cv::dilate(image.getMatrix(), dilatation, kernel);
    return dilatation;
}