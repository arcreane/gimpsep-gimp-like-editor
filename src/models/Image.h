#pragma once
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;

class Image{

    string  title;
    cv::Mat matrix;

public:

    Image() {}

    Image(string path){
        this->title = extractTitleFromPath(path);
        this->setMatrix(path);
    }

    Image(string title, cv::Mat matrix){
        this->title = title;
        this->matrix = matrix;
    }

    string extractTitleFromPath(string path){
        return path.substr(path.find_last_of("/") + 1);
    }

    void setMatrix(string imagePath){
        cv::Mat image;
        image = cv::imread(imagePath, cv::IMREAD_COLOR);
        if(!image.empty()){
            this->matrix = image;
        }
    }

    cv::Mat getMatrix(){
        return this->matrix;
    }

    string getTitle(){
        return this->title;
    }
};
