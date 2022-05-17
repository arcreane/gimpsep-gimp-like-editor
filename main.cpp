#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

cv::Mat loadImage(std::string imageName);
void displayImage(std::string title, cv::Mat image);

int main() {
    std::string happyFishImagePath = "../ressources/images/HappyFish.jpeg";
    std::string windowTitle = "Happy Fish Window";
    cv::Mat happyFishImage = loadImage(happyFishImagePath);
    displayImage(windowTitle,happyFishImage);

    std::cout << "Waiting user to press any key" << std::endl;
    cv::waitKey(0);
    return 0;
}

cv::Mat loadImage(std::string imageName){
    cv::Mat image;
    image = cv::imread(imageName, cv::IMREAD_COLOR);
    if(image.empty()){
        std::cout << "Could not open or find the image" << std::endl;
    }
    return image;
}

void displayImage(std::string title, cv::Mat image){
    cv::namedWindow(title, cv::WINDOW_AUTOSIZE);
    cv::imshow(title, image);
}
