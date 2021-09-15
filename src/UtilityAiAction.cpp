// Created by Quentin Pamart on 15/09/2021.

#include "UtilityAiAction.h"

#include <utility>

UtilityAiAction::UtilityAiAction(std::string desc) : m_description(std::move(desc)){}

float UtilityAiAction::utility(const std::map<std::string, int>& resources) {
    return 0;
}
