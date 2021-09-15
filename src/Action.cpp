//
// Created by Antoine on 14/09/2021.
//

#include <cassert>
#include <utility>
#include <iostream>
#include "Action.h"

Action::Action(const std::string& desc):description(std::move(desc)) {}

void Action::AddEffect(const std::string& string, int value) {
	effects[string] = value;
}

void Action::AddPrecondition(const std::string& string, int value) {
	preconditions[string] = value;
}

void Action::performAction(std::map<std::string, int>& map) {
	for(const auto& effect : effects){
		map[effect.first] += effect.second;
	}
	std::cout << description << std::endl;
}

bool Action::canPerform(const std::map<std::string, int>& map) {
    for(const auto& precondition : preconditions){
        const std::string& key = precondition.first;
        const auto& mapIt = map.find(key);
        assert(mapIt != map.end());
        if(mapIt == map.end())
            return false;
        if(precondition.second < mapIt->second)
            return false;
    }
    return true;
}

int Action::getPrecondition(const std::string& key) const {
    const auto& it = preconditions.find(key);
    assert(it != preconditions.end());
    if(it == preconditions.end()) return -1;
    return it->second;
}

int Action::getEffect(const std::string& key) const {
    const auto& it = effects.find(key);
    assert(it != effects.end());
    if(it == effects.end()) return -1;
    return it->second;
}

const std::map<std::string, int> &Action::getPreconditions() {
    return preconditions;
}
const std::map<std::string, int> &Action::getEffects() {
    return effects;
}
