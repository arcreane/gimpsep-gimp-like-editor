#include "headers/UserAction.h"

string UserAction::getActionName(int key){
    return actions.at(key);
}

string UserAction::getExitAction(){
    return actions.at(-1);
}

string UserAction::getHistoryAction(){
    return actions.at(8);
}

string UserAction::getUndoAction(){
    return actions.at(9);
}

int UserAction::getNumberOfAvailableActions(){
    return actions.size();
};