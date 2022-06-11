#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

class FileName{

public :
    inline static string imageResourceFolderPath = "../assets/images/";

    inline static map<int, string> files = {
            {1, "child.jpeg"},
            {2, "eco.jpeg"},
            {3, "fish.jpeg"},
            {4, "mark.jpeg"},
            {5, "vanGogh.jpeg"},
    };

    static string getFileName(int key){
        return imageResourceFolderPath+files.at(key);
    }

    static int getNumberOfAvailableFiles(){
        return files.size();
    };

};