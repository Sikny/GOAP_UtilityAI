// Created by Quentin Pamart on 15/09/2021.

#pragma once
#include "Action.h"

class UtilityAiAction/* : public Action*/ {
public:
    explicit UtilityAiAction(std::string desc);
    // todo utility args -> parametre a evaluer, max, fonction
    virtual float utility(const std::map<std::string, int>&) = 0;   // [0;1]
    void performAction(std::map<std::string, int>&);
    void AddEffect(const std::string& string, int value);

private:
    std::string m_description;
    std::map<std::string, int> m_effects;
};