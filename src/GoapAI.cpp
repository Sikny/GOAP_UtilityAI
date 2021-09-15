//
// Created by Antoine on 14/09/2021.
//

#include "GoapAI.h"
#include "Action.h"


bool GoapAI::performBestActionPossible() {
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

    return false;
}

void GoapAI::setResource(const std::string & key, int value) {
    resources[key] = value;
}

void GoapAI::addAction(Action * action) {
    actions.push_back(action);
}
