// Created by Quentin Pamart on 16/09/2021.

#pragma once
#include "UtilityAiAction.h"

class UtilityAiActionCollectStone : public UtilityAiAction{
public:
    explicit UtilityAiActionCollectStone(std::string desc, float (*func)(int, int)) : UtilityAiAction(std::move(desc), func) {};
    float utility(const std::map<ActionEnum, int> &map) override;
};

