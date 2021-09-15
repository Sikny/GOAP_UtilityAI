// Created by Quentin Pamart on 15/09/2021.

#include "UtilityAi.h"
#include <algorithm>
#include <iostream>

void UtilityAi::setResource(const std::string & key, int value) {
    resources[key] = value;
}

void UtilityAi::addAction(UtilityAiAction * action) {
    actions.push_back(action);
}

void UtilityAi::tick() {
    float utilityMax = 0;
    UtilityAiAction* selectedAction = nullptr;
    for(const auto& action : actions){
        if(action->utility(resources) > utilityMax){
            selectedAction = action;
            utilityMax = action->utility(resources);
        }
    }
    if(selectedAction != nullptr){
        selectedAction->performAction(resources);
    }
}

void UtilityAi::debug() {
    std::cout << "Current world state :" << std::endl;
    for(const auto& resource : resources){
        std::cout << resource.first << " => " << resource.second << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

int UtilityAi::getResource(const std::string & key) {
    return resources[key];
}
