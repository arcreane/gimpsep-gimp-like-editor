#ifndef GIMP_LIKE_EDITOR_CROP_H
#define GIMP_LIKE_EDITOR_CROP_H

#include "Effect.h"

class Crop : public Effect {
    private:
        int startColumn;
        int startRow;
        int endColumn;
        int endRow;

    public:
        explicit Crop(int startColumn, int startRow, int endColumn, int endRow);

        cv::Mat apply(Image image) override;
};

#endif //GIMP_LIKE_EDITOR_CROP_H
