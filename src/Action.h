//
// Created by Antoine on 14/09/2021.
//

#pragma once
#include <map>
#include <string>
#include "ActionEnum.h"

class Action {
public:
    Action(std::string desc);
    void AddEffect(const ActionEnum& string, int value);
    void performAction(std::map<ActionEnum, int>&);
    [[nodiscard]] std::map<ActionEnum, int>* getEffects();
    std::string toString() const;

protected:
	std::string m_description;
	std::map<ActionEnum, int> m_effects;
};
