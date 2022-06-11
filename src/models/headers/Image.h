#pragma once
#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;

class Image {
    private:
        string  title;
        cv::Mat matrix;

    public:
        Image();
        Image(string path);
        Image(string title, cv::Mat matrix);

        string  extractTitleFromPath(string path);
        void    setMatrix(string imagePath);
        cv::Mat getMatrix();
        string  getTitle();
};
