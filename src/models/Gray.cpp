#include "headers/Gray.h"

Gray::Gray() {}

cv::Mat Gray::apply(Image image) {
    cout << "APPLY blur on " << image.getTitle() << endl;

    cv::Mat Gray;
    cv::cvtColor(image.getMatrix(), Gray, cv::COLOR_BGR2GRAY);
    return Gray;
}
