#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

class UserAction{
    public :
        inline static map<int, string> actions = {
                {1, "DILATATION"},      //size
                {2, "EROSION"},         //size
                {3, "RESIZING"},        //newHeight, newWidth
                {4, "BRIGHTNESS"},      //lightFactor
                {5, "STITCHING"},       //No parameter
                {6, "EDGE DETECTION"},  //No parameter

                {7, "CONVERT TO GREY"},  //TP2
                {8, "CROP"},             //TP2
                {9, "ROTATE"},          //TP2

                {10, "CONTRAST"},        //TP3

                {11, "BLUR"},            //TP5

                {12, "HISTORY"},         //No parameter
                {13, "UNDO"},            //No parameter
                {-1, "QUIT"},            //No parameter
        };

        static string getActionName(int key);
        static string getExitAction();
        static string getHistoryAction();
        static string getUndoAction();
        static int    getNumberOfAvailableActions();
};