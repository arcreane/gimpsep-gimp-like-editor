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
                {6, "mountainCenter.jpeg"},
                {7, "mountainLeft.jpeg"},
                {8, "mountainRight.jpeg"},
        };

        FileName();

        static string getFileName(int key);
        static int    getNumberOfAvailableFiles();
};