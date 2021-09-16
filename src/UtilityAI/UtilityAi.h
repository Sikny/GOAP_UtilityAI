// Created by Quentin Pamart on 15/09/2021.

#pragma once

#include <vector>
#include "UtilityAiAction.h"

class UtilityAi {
public:
    void setResource(const ActionEnum&, int);
    int getResource(const ActionEnum&);
    void addAction(UtilityAiAction*);
    void tick();
    void debug();

private:
    std::map<ActionEnum, int> resources;
    std::vector<UtilityAiAction*> actions;
};


