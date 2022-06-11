#pragma once

#include <iostream>
#include <string>
#include <map>

using namespace std;

#define USER_WANTS_TO_EXIT(userAction) \
    (userAction == ACTION_QUIT)

#define USER_ASK_FOR_STATE_CHANGING(userAction) \
    (userAction == ACTION_HISTORY || userAction == ACTION_UNDO)

typedef enum {
    ACTION_QUIT,
    ACTION_DILATATION,
    ACTION_EROSION,
    ACTION_RESIZING,
    ACTION_BRIGHTNESS,
    ACTION_STITCHING,
    ACTION_EDGE_DETECTION,
    ACTION_CONVERT_TO_GREY,
    ACTION_CROP,
    ACTION_ROTATE,
    ACTION_CONTRAST,
    ACTION_BLUR,
    ACTION_HISTORY,
    ACTION_UNDO,
    ACTION_MAX
} action_e;

static const char * actionNames[] = {
        "QUIT",
        "DILATATION",
        "EROSION",
        "RESIZING",
        "BRIGHTNESS",
        "STITCHING",
        "EDGE DETECTION",
        "CONVERT TO GREY",
        "CROP",
        "ROTATE",
        "CONTRAST",
        "BLUR",
        "HISTORY",
        "UNDO",
        "COMMAND_MAX"
};