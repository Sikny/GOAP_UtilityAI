//
// Created by Antoine on 14/09/2021.
//

#pragma once
#include <map>
#include <string>
#include "ActionEnum.h"

class Action {
public:
    Action(ActionEnum actionEnum, std::string desc);
    void AddEffect(const ActionEnum& string, int value);
    void performAction(std::map<ActionEnum, int>&);
    [[nodiscard]] const std::map<ActionEnum, int>* getEffects() const;
	ActionEnum getActionEnum()const;

protected:
	ActionEnum m_actionEnum;
	std::string m_description;
	std::map<ActionEnum, int> m_effects;
};
