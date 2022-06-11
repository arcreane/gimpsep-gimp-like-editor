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
            {4, "LIGHTEN"},         //lightFactor
            {5, "DARKEN"},          //lightFactor
            {6, "STITCHING"},       //No parameter
            {7, "EDGE DETECTION"},  //No parameter
            {8, "HISTORY"},         //No parameter
            {9, "UNDO"},            //No parameter
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