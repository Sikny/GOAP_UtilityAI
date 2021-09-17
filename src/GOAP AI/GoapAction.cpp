// Created by Quentin Pamart on 15/09/2021.

#include <cassert>
#include <vector>
#include "GoapAction.h"

GoapAction::GoapAction(std::string desc, int cost,
                       std::map<ActionEnum, int>* preconditions, std::map<ActionEnum, int>* effects,
                       std::map<ActionEnum, bool> currentState, GoapAction* parent) : Action(desc), m_cost(cost+parent->getCost()),
                                                                                             m_parent(parent) {
    m_preconditions = *preconditions;

    for(const std::pair<ActionEnum, int> precondition : *preconditions){
        if(precondition.second == 0){
            m_boolPreconditions[precondition.first] = false;
        }else{
            m_boolPreconditions[precondition.first] = true;
        }

    }

    // on créé le nouvel état en partant du précédent
    m_currentState = currentState;

    //on ajoute les potentielles nouvelles contraintes
    for(const std::pair<ActionEnum, bool> precondition : m_boolPreconditions){
        if(!m_currentState.at(precondition.first)){
            m_currentState[precondition.first] = precondition.second;
        }
    }
    //on ajoute les potentielles nouvelles contrainteson résoud les contraintes réalisées par les effets
    for(const std::pair<ActionEnum, int> effect : *effects){
        if((m_currentState.at(effect.first) && effect.second > 0) || (!m_currentState.at(effect.first) && effect.second < 0)){
            m_currentState.erase(effect.first);
        }
    }
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

void GoapAction::AddPrecondition(const ActionEnum& string, int value) {
    m_preconditions[string] = value;
}

int GoapAction::getCost() const {
    return m_cost;
}

std::map<ActionEnum, int>* GoapAction::getPreconditions() {
    return &m_preconditions;
}

void GoapAction::AddChild(GoapAction action) {
    m_children->push_back(&action);
}

std::vector<GoapAction*>* GoapAction::getChildren() const {
    return m_children;
}

int GoapAction::getDistanceToGoal() const {
    return m_currentState.size();
}

std::map<ActionEnum, bool> GoapAction::getCurrentState() {
    return m_currentState;
}

GoapAction* GoapAction::getParent() const {
    return m_parent;
}
