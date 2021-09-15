//
// Created by Antoine on 14/09/2021.
//

#include "GoapAI.h"
#include "Action.h"


bool GoapAI::performBestActionPossible(Action* action) {
    Action* bestAction;
    for (int i = 0; i < actions.size(); ++i) {
        Action* action = actions.at(i);
        //choisi la meilleure action
        bestAction = action;
    }
    if (bestAction->canPerform(resources))
        bestAction->performAction(resources);
    //parcoure les actions
    //trouve la meilleure action

    std::stack<Action*> stk;
    stk.push(action);
    assert(!action->canPerform(resources));
    if(action->canPerform(resources)){
        action->performAction(resources);
        stk.pop();
        return 0;
    }

    std::map<std::string, int> &preconditions = action->getPreconditions();

    int totalCost = 0;
    if(preconditions.size() > 0) {
        for (const auto& pre : preconditions) {
            int wayCost = 0;
            if(pre->first == "hasWood"){
                
            }
        }
    }

    return false;
}

void GoapAI::setResource(const std::string & key, int value) {
    resources[key] = value;
}

void GoapAI::addAction(Action * action) {
    actions.push_back(action);
}
