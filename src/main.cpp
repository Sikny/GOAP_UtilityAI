//
// Created by Antoine on 14/09/2021.
//
#include "GoapAI.h"
#include "Action.h"

int main(int argc, char** argv){
    GoapAI AI;
    AI.setResource("hasWood", rand() % 11 + 0);
    AI.setResource("hasPlank", rand() % 11 + 0);
    AI.setResource("hasHouse", rand() % 11 + 0);

    Action* chopWood = new Action(3,"Chop wood");
    chopWood->AddEffect("hasWood", 3);
    AI.addAction(chopWood);

    Action* createPlank = new Action(2,"Create plank");
    createPlank->AddPrecondition("hasWood", 5);
    createPlank->AddEffect("hasPlank", 1);
    createPlank->AddEffect("hasWood", -5);
    AI.addAction(createPlank);

    Action* createHouse = new Action(1,"Build house");
    createPlank->AddPrecondition("hasPlank", 25);
    createPlank->AddEffect("hasHouse", 1);
    createPlank->AddEffect("hasPlank", -25);
    AI.addAction(createPlank);

	for(int i = 0 ; i < 100 ; ++i){
		AI.performBestActionPossible();
	}
}
