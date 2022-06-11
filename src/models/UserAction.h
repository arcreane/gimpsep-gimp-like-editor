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
            {6, "STITCHING"},       //No parameter
            {7, "EDGE DETECTION"},  //No parameter

            {8, "CONVERT TO GREY"},  //TP2
            {9, "CROP"},             //TP2
            {10, "ROTATE"},          //TP2

            {11, "CONTRAST"},        //TP3

            {12, "BLUR"},            //TP5

            {13, "HISTORY"},         //No parameter
            {14, "UNDO"},            //No parameter
            {-1, "QUIT"},
    };


    static string getActionName(int key){
        return actions.at(key);
    }

    static string getExitAction(){
        return actions.at(-1);
    }

    static string getHistoryAction(){
        return actions.at(8);
    }

    static string getUndoAction(){
        return actions.at(9);
    }

    static int getNumberOfAvailableActions(){
        return actions.size();
    };

};