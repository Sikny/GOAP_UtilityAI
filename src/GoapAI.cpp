//
// Created by Antoine on 14/09/2021.
//

#include "GoapAI.h"
#include "Action.h"

GoapAI::GoapAI() {
	resources["hasWood"] = 0;
	resources["hasPlank"] = 0;
	resources["hasHouse"] = 0;

    Action* chopWoodAction = new Action();
    chopWoodAction->AddEffect("hasWood",3);
	actions.push_back(chopWoodAction);

	Action* createPlank = new Action();
	createPlank->AddPrecondition("hasWood",5);
	createPlank->AddEffect("hasPlank",1);
	actions.push_back(createPlank);

	Action* createHouse = new Action();
	createPlank->AddPrecondition("hasPlank",25);
	createPlank->AddEffect("hasHouse",1);
	actions.push_back(createPlank);
}

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


