#include "../headers/effects/Crop.h"

Crop::Crop(int startColumn, int startRow, int endColumn, int endRow) : startColumn(startColumn), startRow(startRow), endColumn(endColumn), endRow(endRow) {}

cv::Mat Crop::apply(Image image) {
    return image.getMatrix()(cv::Range(startColumn, startRow), cv::Range(endColumn, endRow));
}

