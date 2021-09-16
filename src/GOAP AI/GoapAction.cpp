// Created by Quentin Pamart on 15/09/2021.

#include <cassert>
#include "GoapAction.h"

GoapAction::GoapAction(int cost, std::string desc) : m_cost(cost), Action(std::move(desc)) {}

void GoapAction::AddPrecondition(const ActionEnum& string, int value) {
    m_preconditions[string] = value;
}

int GoapAction::getCost() const {
    return m_cost;
}

bool GoapAction::canPerform(const std::map<ActionEnum, int>& map) const {
    for(const auto& precondition : m_preconditions){
        const ActionEnum& key = precondition.first;
        const auto& mapIt = map.find(key);
        assert(mapIt != map.end());
        if(mapIt == map.end())
            return false;
        if(precondition.second > mapIt->second)
            return false;
    }
    return true;
}

const std::map<ActionEnum, int> & GoapAction::getPreconditions() const {
    return m_preconditions;
}