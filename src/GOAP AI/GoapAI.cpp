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
bool GoapAI::planActions(std::vector<ActionEnum>& finalActions) {
	std::map<ActionEnum, bool> *goalPreconditions = convertConditionsToBool(m_goal->getPreconditions());

	//goal node
	GOAPTreeNode goalNode(hasHouse,
						  m_goal->getCost(),
						  convertConditionsToBool(m_goal->getPreconditions()),
						  convertConditionsToBool(m_goal->getEffects()),
						  convertConditionsToBool(m_goal->getPreconditions()));

	//Adding the first nodes
	for (const GoapAction *action: m_actions) {
		GOAPTreeNode currentActionNode(action->getActionEnum(),
									   action->getCost(),
									   convertConditionsToBool(action->getPreconditions()),
									   convertConditionsToBool(action->getEffects()),
									   goalPreconditions,
									   &goalNode);
		goalNode.addChild(currentActionNode);
		//action, cost, preconditions, effects, currentState, parent
	}

	std::vector<std::vector<GOAPTreeNode *>> openNodeStructure;
	for (int i = 0; i < resources.size() - 1; ++i) {
		openNodeStructure.emplace_back(std::vector<ActionEnum>());
	}
	//On va parcourir les enfants pour les sauvegarder dans le tableau openNode en fonction de leur distance par rapport à l'objectif
	std::vector<GOAPTreeNode&> children;
	for (int i = 0; i < children.size(); ++i) {
		openNodeStructure.at(children[i].getDistanceToGoal() - 1).emplace_back(children[i]);
	}
	// on va parcourir le tableau en parcourant de la plus petite distance à la plus grande
	for (int i = 0; i < openNodeStructure.size(); ++i) {
		std::vector<GOAPTreeNode *> currentListOfNodes = openNodeStructure.at(i);//la liste des openNodes pour la distance actuelle
		for (int j = 0; j < currentListOfNodes.size(); ++i) {//on parcours cette liste
			GOAPTreeNode *currentNode = currentListOfNodes.at(j);

			//On construit une liste d'ActionEnum contenant toutes les actions possibles sauf l'action actuelle
			std::vector<ActionEnum> possibleActions;
			ActionEnum currentActionEnum = currentNode->getActionEnum();
			for(int x = 0; x < m_actionEnums.size(); ++x) {
				if(m_actionEnums.at(i) != currentActionEnum) {
					possibleActions.push_back(m_actionEnums.at(i));
				}
			}


			//depuis cette liste on va générer la liste des sous nodes
			for (int k = 0; k < possibleActions.size(); ++k) {

				//On récupère le GoapAction correspondant à l'Enum
				GoapAction* currentGoapAction = getActionForActionEnum(possibleActions.at(k));

				GOAPTreeNode currentActionNode(possibleActions.at(k),
											   currentGoapAction->getCost(),
											   convertConditionsToBool(currentGoapAction->getPreconditions()),
											   convertConditionsToBool(currentGoapAction->getEffects()),
											   goalPreconditions,
											   &goalNode);
				//add to parent
				if(currentActionNode.getDistanceToGoal() <= 0){
					//on a trouvé un chemin possible;
					//on le retire d'openNode
					openNodeStructure.pop_back();
				}
				currentNode->addChild(currentActionNode);


			}
		}
	}
}
std::map<ActionEnum, bool>* GoapAI::convertConditionsToBool(const std::map<ActionEnum, int>* map) const{
	std::map<ActionEnum, bool>* boolConditions;
	for(auto m : *map){
		if(m.second <= resources.at(m.first))
			boolConditions->at(m.first) = true;
		else boolConditions->at(m.first) = false;
	}
	return boolConditions;
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
    for(GoapAction* ac : m_actions)
    {
        auto effects = ac->getEffects();
        if(effects->find(effect) != effects->end()){
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
	m_actionEnums.push_back(action->getActionEnum());
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

GoapAction *GoapAI::getActionForActionEnum(ActionEnum actionEnum) const {
	for(int i = 0; i < m_actions.size(); ++i){
		if(m_actions.at(i)->getActionEnum() == actionEnum)
			return m_actions.at(i);
	}
	return nullptr;
}
