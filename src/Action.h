//
// Created by Antoine on 14/09/2021.
//

#pragma once
#include <map>
#include <string>

class Action {
public:
    Action(std::string desc);
    void AddEffect(const std::string& string, int value);
    void performAction(std::map<std::string, int>&);
    const std::map<std::string, int>& getEffects();

protected:
	std::string m_description;
	std::map<std::string, int> m_effects;
};
