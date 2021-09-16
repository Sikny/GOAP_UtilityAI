//
// Created by Antoine on 14/09/2021.
//

#include "GoapAI.h"
#include "GoapAction.h"
#include "GOAPTreeNode.h"
#include <iostream>

bool GoapAI::performBestActionPossible() {



	return true;
}

///Gets the stack of actions required to make a given action and its cost
/// - Returns : true if end of stack ? false if jsp frérot
bool GoapAI::planActions(std::vector<ActionEnum>& finalActions)  {
	std::map<ActionEnum,bool>* goalPreconditions = convertConditionsToBool(m_goal->getPreconditions());
	GOAPTreeNode* goalNode(hasHouse, m_goal->getCost(), , {}, nullptr);
	for(const GoapAction* action : actions){
		GOAPTreeNode currentActionNode(action->getActionEnum(),
									   action->getCost(),
									   convertConditionsToBool(action->getPreconditions()),
									   convertConditionsToBool(action->getEffects()),
									   goalPreconditions,
									   goalNode);
		goalNode->addChild(currentActionNode);
		
		//action, cost, preconditions, effects, currentState, parent
	}
}

std::map<ActionEnum, bool>* GoapAI::convertConditionsToBool(const std::map<ActionEnum, int>* map) const{

}

void GoapAI::mergeStack(std::stack<GoapAction*>& s1, std::stack<GoapAction*>& s2) const{
    std::stack<GoapAction*> tmp;

    for(int i = 0; i < s2.size(); i++){
        tmp.push(s2.top());
        s2.pop();
    }

    for(int i = 0; i < tmp.size(); i++) {
        s1.push(tmp.top());
        tmp.pop();
    }
}

void
GoapAI::getMissingPreconditions(const GoapAction *action, std::map<ActionEnum, int>& missingPreconditions) const {//si on ne peut pas encore réaliser l'action :
    for(auto& precond : action->getPreconditions()){
        if(tmpResources.at(precond.first) < precond.second){
            missingPreconditions[precond.first] = precond.second;
        }
    }
}

void GoapAI::findActionsOfEffect(ActionEnum effect, std::vector<std::tuple<GoapAction*,int>>& compatibleActions) const {
    for(GoapAction* ac : actions)
    {
        auto effects = ac->getEffects();
        if(effects.find(effect) != effects.end()){
            int cost = ac->getCost();

            compatibleActions.push_back(std::make_tuple(ac,cost));
        }
    }
}

void GoapAI::setResource(const ActionEnum & key, int value) {
    resources[key] = value;
    tmpResources = resources;
}

void GoapAI::addAction(GoapAction * action) {
    m_actions.push_back(action);
}

void GoapAI::debug() {
    std::cout << "Current world state :" << std::endl;
    for(const auto& resource : resources){
        std::cout << actionStrings.at(resource.first) << " => " << resource.second << std::endl;
    }
    std::cout << "------------------------" << std::endl;
}

void GoapAI::setGoal(GoapAction* goal) {
	m_goal = goal;
}
