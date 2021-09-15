// Created by Quentin Pamart on 15/09/2021.

#pragma once
#include "Action.h"

class UtilityAiAction/* : public Action*/ {
public:
    explicit UtilityAiAction(std::string  desc);
    float utility(const std::map<std::string, int>&);

private:
    std::string m_description;
};


