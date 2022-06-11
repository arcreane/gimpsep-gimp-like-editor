#ifndef GIMP_LIKE_EDITOR_CONTRAST_H
#define GIMP_LIKE_EDITOR_CONTRAST_H

#include "Effect.h"

class Contrast : public Effect {
    private:
        float contrastValue;

    public:

        explicit Contrast(float contrastValue);

        cv::Mat apply(Image image) override;
};


#endif //GIMP_LIKE_EDITOR_CONTRAST_H
