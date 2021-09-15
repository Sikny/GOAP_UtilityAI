// Created by Quentin Pamart on 15/09/2021.

#include "UtilityAiAction.h"

#include <utility>
#include <iostream>

UtilityAiAction::UtilityAiAction(std::string desc) : m_description(std::move(desc)){}

void UtilityAiAction::performAction(std::map<std::string, int>& map) {
    for(const auto& effect : m_effects){
        map[effect.first] += effect.second;
    }
    std::cout << m_description << std::endl;
}