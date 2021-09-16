//
// Created by Marine on 16/09/2021.
//

#include "GOAPTreeNode.h"

#include <utility>

GOAPTreeNode::GOAPTreeNode(ActionEnum action, int cost, std::map<ActionEnum,bool>* preconditions, std::map<ActionEnum,bool>* effects, std::map<ActionEnum,bool>* currentState,
						   GOAPTreeNode *parent) : m_action(action), m_cost(cost), m_preconditions(std::move(preconditions)), m_effects(std::move(effects)), m_parent(parent) {
	for(const auto state : currentState){
		for(const auto preco : m_preconditions){
			bool preconditionOfState = preco[state->first];

			if(preconditionOfState != nullptr && state->second && !preco[state->first])
		}
		m_currentState[state->first] =
	}
}
int GOAPTreeNode::getDistanceToGoal() const {
	return ;
}

void GOAPTreeNode::addChild(GOAPTreeNode *child) {
	m_children.push_back(child);
}
