//
// Created by Antoine on 14/09/2021.
//
#include "GoapAI.h"
#include "Action.h"

int main(int argc, char** argv){
    GoapAI AI;
    AI.setResource("hasWood", 0);
    AI.setResource("hasPlank", 0);
    AI.setResource("hasHouse", 0);

    Action* chopWood = new Action("Chop wood");
    chopWood->AddEffect("hasWood", 3);
    AI.addAction(chopWood);

    Action* createPlank = new Action("Create plank");
    createPlank->AddPrecondition("hasWood", 5);
    createPlank->AddEffect("hasPlank", 1);
    AI.addAction(createPlank);

    Action* createHouse = new Action("Build house");
    createPlank->AddPrecondition("hasPlank", 25);
    createPlank->AddEffect("hasHouse", 1);
    AI.addAction(createPlank)

	for(int i = 0 ; i < 100 ; ++i){
		AI.performBestActionPossible();
	}
}
