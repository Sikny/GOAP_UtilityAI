//
// Created by Antoine on 14/09/2021.
//

#include "GoapAI.h"
#include "../Action.h"
#include <iostream>

bool GoapAI::performBestActionPossible() {

    int currentLowestCost = 1000000;
    std::stack<Action*> bestActionsToPerfom;
    for(Action* action : actions){
        if(action->canPerform(tmpResources)) {
            int *cost = new int(0);

            std::stack<Action *> stk;
            getActionsAndCost(action, cost, stk);
            if (*cost < currentLowestCost) {
                bestActionsToPerfom = stk;
                currentLowestCost = *cost;
            }
        }
        else break;
    }

    for(int i = 0; i < bestActionsToPerfom.size(); i++){
        if(bestActionsToPerfom.top()->canPerform(resources))
            bestActionsToPerfom.top()->performAction(resources);
        bestActionsToPerfom.pop();
    }
    return true;
}

///Gets the stack of actions required to make a given action and its cost
/// - Returns : true if end of stack ? false if jsp frérot
bool GoapAI::getActionsAndCost(Action *action, int *cost, std::stack<Action *> &stk)  {
    stk.push(action); //on ajoute l'action à la pile
    *cost += action->getCost();
    if (action->canPerform(tmpResources)){
        action->performAction(tmpResources);
        return true;
    }

    std::map<std::string,int> missingPreconditions;
    getMissingPreconditions(action, missingPreconditions);

    for (const auto& pre : missingPreconditions) {
        int wayCost = 0;

        std::vector<std::tuple<Action*,int>> compatibleActions;
        findActionsOfEffect(pre.first, compatibleActions);

        int currentLowestCost = 200;
        std::stack<Action*> bestActionsToPerfom;
        for(std::tuple<Action*,int> actionForPrecondition : compatibleActions){
            int* tmpCost = new int(200);
            std::stack<Action*> tmpStk;
            getActionsAndCost(get<0>(actionForPrecondition), tmpCost, tmpStk);
            if(*tmpCost < currentLowestCost){
                bestActionsToPerfom = tmpStk;
                currentLowestCost = *tmpCost;
                get<0>(actionForPrecondition)->performAction(tmpResources);
            }
        }

        cost += currentLowestCost;
        mergeStack(stk,bestActionsToPerfom);

    }
    return false;
}

void GoapAI::mergeStack(std::stack<Action*>& s1, std::stack<Action*>& s2) const{
    std::stack<Action*> tmp;

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
GoapAI::getMissingPreconditions(const Action *action, std::map<std::string, int>& missingPreconditions) const {//si on ne peut pas encore réaliser l'action :
    for(auto& precond : action->getPreconditions()){
        if(tmpResources.at(precond.first) < precond.second){
            missingPreconditions[precond.first] = precond.second;
        }
    }
}

void GoapAI::findActionsOfEffect(std::string effect, std::vector<std::tuple<Action*,int>>& compatibleActions) const {
    for(Action* ac : actions)
    {
        auto effects = ac->getEffects();
        if(effects.find(effect) != effects.end()){
            int cost = ac->getCost();

            compatibleActions.push_back(std::make_tuple(ac,cost));
        }
    }
}

void GoapAI::setResource(const std::string & key, int value) {
    resources[key] = value;
    tmpResources = resources;
}

void GoapAI::addAction(Action * action) {
    actions.push_back(action);
}
