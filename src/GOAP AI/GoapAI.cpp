//
// Created by Antoine on 14/09/2021.
//

#include "GoapAI.h"
#include "GoapAction.h"
#include "GOAPTreeNode.h"
#include <iostream>

bool GoapAI::performBestActionPossible() {
    GoapAction* bestGoapNode = planActions();
    //on remonte les actions jusqu'à tomber sur le goal (qui n'a pas de parent)

    for (int i = 0; i < 100 || bestGoapNode->getParent() != nullptr; ++i) {//boucle while qui peut break
        for (int j = 0;j < 100 || bestGoapNode->getParent()->canPerform(resources); ++j) {//boucle while qui peut break
            for(std::pair<ActionEnum,int> effect : *bestGoapNode->getEffects()){
                resources[effect.first] += effect.second;
            }
            debug();
        }
        //on a réalisé notre tache et on passe à la suite.
        bestGoapNode = bestGoapNode->getParent();
    }
    return true;
}

GoapAction* GoapAI::planActions() {

    std::cout << "Begin planning" << std::endl;

    std::vector<GoapAction*> openNodeVector;
    GoapAction* bestGoapNode;

    for(GoapAction* action : m_actions){
        std::cout << "Action " << action->toString() << " added to goal as children" << std::endl;
        GoapAction newAction(action->toString(), action->getCost(), action->getPreconditions(),
                             action->getEffects(), m_goal->getCurrentState(), m_goal);
        m_goal->AddChild(newAction);
    }
    for(GoapAction* action : *m_goal->getChildren()){
        std::cout << "Action " << action->toString() << " added to openNodeVector" << std::endl;
        openNodeVector.push_back(action);
    }

    while(openNodeVector.size() > 0){
        int currentPreconditionAmount = 123131321;
        GoapAction* currentNode;

        //on trouve la distance par rapport a l'objectif la plus faible
        for(GoapAction* availableAction : openNodeVector){
            if(availableAction->getDistanceToGoal() < currentPreconditionAmount)
                currentPreconditionAmount = availableAction->getDistanceToGoal();
        }

        //des qu'on tombe sur un node ayant cette distance, on le prend comme node actuel et on le retire de la liste
        for(auto it = openNodeVector.begin(); it != openNodeVector.end(); it++){
            if((*it)->getDistanceToGoal() == currentPreconditionAmount){
                currentNode = (*it);
                openNodeVector.erase(it);
                break;
            }
        }

        if(currentPreconditionAmount == 0){ //mashallah on a une feuille c'est la fête
            if(bestGoapNode == nullptr || (bestGoapNode->getCost() > currentNode->getCost())){
                bestGoapNode = currentNode;
            }
        }else{//si notre node n'est pas une feuille on tente d'ajouter des enfants

            //on sélectionne toutes les actions sauf l'action actuelle
            std::vector<GoapAction*> availableActions;
            for(GoapAction* action : m_actions){
                if(action->getPreconditions() == currentNode->getPreconditions() && action->getEffects() == currentNode->getEffects())
                    continue;
                availableActions.push_back(action);
            }

            for(GoapAction* action : availableActions){
                GoapAction newSubAction(action->toString(), action->getCost(), action->getPreconditions(),
                                        action->getEffects(), m_goal->getCurrentState(), m_goal);
                //on ajoute uniquement les nodes qui ont un cout total inférieur au meilleur chemin actuel si déjà trouvé
                if(bestGoapNode != nullptr && newSubAction.getCost() > bestGoapNode->getCost()){
                    continue;
                }
                currentNode->AddChild(newSubAction);
            }
            //on ajoute les enfants valides au openNode pour les parcourir à la prochaine boucle du while
            for(GoapAction* action : *currentNode->getChildren()){
                openNodeVector.push_back(action);
            }
        }

    }
    //on retourne le node optimum
    return bestGoapNode;
}


/*
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
}*/

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
