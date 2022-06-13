#include "../headers/effects/Erosion.h"


cv::Mat Erosion::apply(Image image){
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * this->size + 1, 2 * this->size + 1));

    cv::Mat erosion;
    cv::erode(image.getMatrix(), erosion, kernel);
    return erosion;
}

void Erosion::setParametersFromUserInput(){
    int size = 0;
    while(size < Erosion::MIN_SIZE || size> Erosion::MAX_SIZE){
        cout << "Enter erosion size [" << Erosion::MIN_SIZE << "-" << Erosion::MAX_SIZE << "] :" << endl;
        cin >> size;
    }
    this->size = size;
}