#include "../headers/effects/Dilatation.h"


cv::Mat Dilatation::apply(Image image){
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * this->size + 1, 2 * this->size + 1));
    cv::Mat dilatation;
    cv::dilate(image.getMatrix(), dilatation, kernel);
    return dilatation;
}

void Dilatation::setParametersFromUserInput(){
    int size = 0;
    while(size < Dilatation::MIN_SIZE || size> Dilatation::MAX_SIZE){
        cout << "Enter dilatation size [" << Dilatation::MIN_SIZE << "-" << Dilatation::MAX_SIZE << "] :" << endl;
        cin >> size;
    }
    this->size = size;
}