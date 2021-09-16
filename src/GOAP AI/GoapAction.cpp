// Created by Quentin Pamart on 15/09/2021.

#include <cassert>
#include "GoapAction.h"

GoapAction::GoapAction(int cost, std::string desc) : m_cost(cost), Action(std::move(desc)) {}

void GoapAction::AddPrecondition(const std::string& string, int value) {
    m_preconditions[string] = value;
}

int GoapAction::getCost() const {
    return m_cost;
}

bool GoapAction::canPerform(const std::map<std::string, int>& map) const {
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

const std::map<std::string, int> & GoapAction::getPreconditions() const {
    return m_preconditions;
}