//
// Created by Antoine on 14/09/2021.
//

#include <cassert>
#include <utility>
#include <iostream>
#include "Action.h"

Action::Action(int cost, std::string desc): m_cost(cost), m_description(std::move(desc)) {}

void Action::AddEffect(const std::string& string, int value) {
	m_effects[string] = value;
}

void Action::AddPrecondition(const std::string& string, int value) {
	m_preconditions[string] = value;
}

void Action::performAction(std::map<std::string, int>& map) {
	for(const auto& effect : m_effects){
		map[effect.first] += effect.second;
	}
	std::cout << m_description << std::endl;
}

bool Action::canPerform(const std::map<std::string, int>& map) const {
    for(const auto& precondition : m_preconditions){
        const std::string& key = precondition.first;
        const auto& mapIt = map.find(key);
        assert(mapIt != map.end());
        if(mapIt == map.end())
            return false;
        if(precondition.second > mapIt->second)
            return false;
    }
    return true;
}

int Action::getPrecondition(const std::string& key) const {
    const auto& it = m_preconditions.find(key);
    assert(it != m_preconditions.end());
    if(it == m_preconditions.end()) return -1;
    return it->second;
}

int Action::getEffect(const std::string& key) const {
    const auto& it = m_effects.find(key);
    assert(it != m_effects.end());
    if(it == m_effects.end()) return -1;
    return it->second;
}

const std::map<std::string, int> &Action::getPreconditions() const {
    return m_preconditions;
}
const std::map<std::string, int> &Action::getEffects() {
    return m_effects;
}

int Action::getCost() const {
	return m_cost;
}
