//
// Created by Antoine on 14/09/2021.
//

#include <utility>
#include <iostream>
#include "Action.h"

Action::Action(std::string desc): m_description(std::move(desc)) {}

void Action::AddEffect(const std::string& string, int value) {
	m_effects[string] = value;
}


void Action::performAction(std::map<std::string, int>& map) {
	for(const auto& effect : m_effects){
		map[effect.first] += effect.second;
	}
	std::cout << m_description << std::endl;
}

const std::map<std::string, int> &Action::getEffects() {
    return m_effects;
}

