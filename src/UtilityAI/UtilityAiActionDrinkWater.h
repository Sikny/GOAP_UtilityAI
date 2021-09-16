// Created by Quentin Pamart on 16/09/2021.

#pragma once


#include "UtilityAiAction.h"

class UtilityAiActionDrinkWater : public UtilityAiAction {
public:
    explicit UtilityAiActionDrinkWater(std::string desc, float (*func)(int, int)) : UtilityAiAction(std::move(desc), func) {};
    float utility(const std::map<std::string, int> &map) override;

};


