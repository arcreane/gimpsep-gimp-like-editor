#ifndef GIMP_LIKE_EDITOR_RESIZE_H
#define GIMP_LIKE_EDITOR_RESIZE_H

#include "Effect.h"

class Resize : public Effect {
    private:
        int    width;
        int    height;
        double scaleX;
        double scaleY;

    public:
        explicit Resize(double scaleX, double scaleY);
        explicit Resize(int width, int height);

        cv::Mat apply(Image image) override;
};

#endif //GIMP_LIKE_EDITOR_RESIZE_H
