// Created by Quentin Pamart on 15/09/2021.

#pragma once
#include "UtilityAiAction.h"

class UtilityAiActionCreatePlank : public UtilityAiAction {
public:
    explicit UtilityAiActionCreatePlank(std::string desc, float (*func)(int, int)) : UtilityAiAction(std::move(desc), func) {};
    float utility(const std::map<ActionEnum, int> &map) override;
};


