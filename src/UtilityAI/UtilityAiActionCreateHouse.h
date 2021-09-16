// Created by Quentin Pamart on 15/09/2021.

#pragma once
#include <utility>

#include "UtilityAiAction.h"

class UtilityAiActionCreateHouse : public UtilityAiAction {
public:
    explicit UtilityAiActionCreateHouse(std::string desc) : UtilityAiAction(std::move(desc), nullptr) {};
    float utility(const std::map<ActionEnum, int> &map) override;
};


