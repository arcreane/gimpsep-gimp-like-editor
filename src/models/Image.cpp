#include "headers/Image.h"

Image::Image() {}

Image::Image(string path) {
    this->title = extractTitleFromPath(path);
    this->setMatrix(path);
}

Image::Image(string title, cv::Mat matrix) {
    this->title = title;
    this->matrix = matrix;
}

string Image::extractTitleFromPath(string path) {
    return path.substr(path.find_last_of("/") + 1);
}

void Image::setMatrix(string imagePath) {
    cv::Mat image;
    image = cv::imread(imagePath, cv::IMREAD_COLOR);
    if(!image.empty()){
        this->matrix = image;
    }
}

cv::Mat Image::getMatrix() {
    return this->matrix;
}

string Image::getTitle() {
    return this->title;
}