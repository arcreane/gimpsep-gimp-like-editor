#include <iostream>
#include <vector>
#include "../../models/headers/Image.h"

#pragma once

class Subject;

class Observer{
    public:
        virtual ~Observer() = default;
        virtual void beforeChangeUpdate(Subject& changedSubject) = 0;
        virtual void afterChangeUpdate(Subject& changedSubject, Image image, string specialAction) = 0;
};
