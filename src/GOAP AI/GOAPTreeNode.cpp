//
// Created by Marine on 16/09/2021.
//

#include "GOAPTreeNode.h"

#include <utility>
/*
GOAPTreeNode::GOAPTreeNode(ActionEnum action, int cost, const std::map<ActionEnum,bool>* preconditions, const std::map<ActionEnum,bool>* effects, const std::map<ActionEnum,bool>* currentState,
						   GOAPTreeNode* parent = nullptr) : m_action(action), m_cost(cost), m_preconditions(std::move(preconditions)), m_effects(std::move(effects)), m_parent(parent) {
	for(const auto state : currentState){//parcoure les préconditions actuelles de l'état de l'objectif
		if(effects.at(state.first) == nullptr)
			m_currentState[state.first] = state.second;
	}
	for(const auto preco : m_preconditions){//parcoure les préconditions de mon action
		if(state.at(preco.first) == nullptr)
			m_currentState[preco.first] = preco.second;
	}
}
int GOAPTreeNode::getDistanceToGoal() const {
	return m_currentState.count;
}

void GOAPTreeNode::addChild(GOAPTreeNode& child) {
	m_children.push_back(child);
}

std::vector<GOAPTreeNode&> GOAPTreeNode::getChildren() const {
	return m_children;
}

ActionEnum GOAPTreeNode::getActionEnum() const {
	return m_action;
}
*/