#include <iostream>
#include <vector>

#include "../../models/headers/Image.h"
#include "../../models/headers/UserAction.h"

#pragma once

class Subject;
class Observer {
    public:
        virtual ~Observer() = default;
        virtual void beforeChangeUpdate(Subject& changedSubject) = 0;
        virtual void afterChangeUpdate(Subject& changedSubject, Image image, action_e specialAction) = 0;
};
