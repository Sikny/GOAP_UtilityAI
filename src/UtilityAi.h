// Created by Quentin Pamart on 15/09/2021.

#pragma once

#include <vector>
#include "UtilityAiAction.h"

class UtilityAi {
public:
    void setResource(const std::string&, int);
    int getResource(const std::string&);
    void addAction(UtilityAiAction*);
    void tick();
    void debug();

private:
    std::map<std::string, int> resources;
    std::vector<UtilityAiAction*> actions;
};


