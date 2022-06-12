#include "../headers/effects/Gray.h"

Gray::Gray() {}

cv::Mat Gray::apply(Image image) {

    cv::Mat Gray;
    cv::cvtColor(image.getMatrix(), Gray, cv::COLOR_BGR2GRAY);
    return Gray;
}
