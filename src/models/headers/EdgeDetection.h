#ifndef GIMP_LIKE_EDITOR_EDGEDETECTION_H
#define GIMP_LIKE_EDITOR_EDGEDETECTION_H

#include "Effect.h"

class EdgeDetection : public Effect {
    private:

    public:
        explicit EdgeDetection();

        cv::Mat apply(Image image) override;
};

#endif //GIMP_LIKE_EDITOR_EDGEDETECTION_H
