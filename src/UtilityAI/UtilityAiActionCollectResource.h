// Created by Quentin Pamart on 17/09/2021.

#pragma once
#include <utility>

#include "UtilityAiAction.h"

class UtilityAiActionCollectResource : public UtilityAiAction{
public:
    explicit UtilityAiActionCollectResource(std::string desc, float (*func) (int, int), ActionEnum resourceType, int pResourceMax)
        : UtilityAiAction(std::move(desc), func), resource(resourceType), resourceMax(pResourceMax) {}
    float utility(const std::map<ActionEnum, int>& map) override;
private:
    ActionEnum resource;
    int resourceMax;
};


