#include "../headers/effects/Stitching.h"

Stitching::Stitching() {}

cv::Mat Stitching::apply(Image image) {
    std::vector<cv::Mat> imagesVector;

    image.setMatrix("../assets/images/mountainLeft.jpeg");
    imagesVector.push_back(image.getMatrix());

    image.setMatrix("../assets/images/mountainCenter.jpeg");
    imagesVector.push_back(image.getMatrix());

    image.setMatrix("../assets/images/mountainright.jpeg");
    imagesVector.push_back(image.getMatrix());

    cv::Mat pano;
    cv::Stitcher::Mode mode = cv::Stitcher::PANORAMA;

    cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create(mode);

    cv::Stitcher::Status status = stitcher->stitch(imagesVector, pano);

    if (status != cv::Stitcher::OK)
    {
        std::cout << "Can't stitch images\n" << std::endl;
    }

    return pano;
}