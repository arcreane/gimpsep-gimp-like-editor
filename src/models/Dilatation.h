#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include "Effect.h"
#include "Image.h"
using namespace std;



class Dilatation : public Effect{
    int size;
public:

    Dilatation(int size){
        this->size = size;
    }

    cv::Mat apply(Image image){
        cout << "APPLY dilatation on " << image.getTitle() << endl;

        cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * this->size + 1, 2 * this->size + 1));

        cv::Mat dilatation;
        cv::dilate(image.getMatrix(), dilatation, kernel);
        return dilatation;
    }


};
