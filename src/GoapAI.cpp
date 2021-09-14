//
// Created by Antoine on 14/09/2021.
//

#include "GoapAI.h"
#include "Action.h"

GoapAI::GoapAI() {
    Action* chopWoodAction = new Action();
    preconditions["hasWood"] = false;
    chopWoodAction->AddEffect("hasWood");
    chopWoodAction->AddPrecondition("canChop");
    actions.push_back(chopWoodAction);
}

bool GoapAI::performBestActionPossible() {
    Action* bestAction;
    for (int i = 0; i < actions.size(); ++i) {
        Action* action = actions.at(i);
        //choisi la meilleure action
        bestAction = action;
    }
    if (bestAction->canPerform(preconditions))
        bestAction->performAction(preconditions);
    //parcoure les actions
    //trouve la meilleure action

    return false;
}


