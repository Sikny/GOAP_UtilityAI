// Created by Quentin Pamart on 16/09/2021.

#pragma once
#include "UtilityAiAction.h"

class UtilityAiActionCreateWall : public UtilityAiAction {
public:
    explicit UtilityAiActionCreateWall(std::string desc, float (*func)(int, int)) : UtilityAiAction(std::move(desc), func) {};
    float utility(const std::map<std::string, int> &map) override;
};


