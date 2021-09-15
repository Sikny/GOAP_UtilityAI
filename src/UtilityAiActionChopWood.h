// Created by Quentin Pamart on 15/09/2021.

#pragma once
#include "UtilityAiAction.h"

class UtilityAiActionChopWood : public UtilityAiAction {
public:
    float utility(const std::map<std::string, int> &map) override;

};


