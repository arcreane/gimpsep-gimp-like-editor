#include "headers/FileName.h"

FileName::FileName() {}

string FileName::getFileName(int key){
    return imageResourceFolderPath+files.at(key);
}

int FileName::getNumberOfAvailableFiles(){
    return files.size();
};
