//
// Created by Antoine on 14/09/2021.
//
#include "GoapAI.h"
#include "UtilityAi.h"
#include "UtilityAiActionChopWood.h"
#include "UtilityAiActionCreatePlank.h"
#include "UtilityAiActionCreateHouse.h"
#include "World.h"
#include <windows.h>
#include <iostream>

int main(int argc, char** argv){
    /*GoapAI AI;
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
	}*/
    UtilityAi ai;
    ai.setResource("hasWood", rand() % 11 + 0);
    ai.setResource("hasPlank", rand() % 11 + 0);
    ai.setResource("hasHouse", rand() % 11 + 0);
    int houseCountStart = ai.getResource("hasHouse");
    ai.debug();

    UtilityAiAction* chopWood = new UtilityAiActionChopWood("Chop wood");
    chopWood->AddEffect("hasWood", 3);
    ai.addAction(chopWood);

    UtilityAiAction* createPlank = new UtilityAiActionCreatePlank("Create plank");
    createPlank->AddEffect("hasPlank", 1);
    createPlank->AddEffect("hasWood", -5);
    ai.addAction(createPlank);

    UtilityAiAction* createHouse = new UtilityAiActionCreateHouse("Build house");
    createHouse->AddEffect("hasHouse", 1);
    createHouse->AddEffect("hasPlank", -25);
    ai.addAction(createHouse);

    World world;
    int i = 0;
    while(i++ < 99 && (ai.getResource("hasHouse") - houseCountStart) < 2){
        ai.tick();
        ai.debug();
        Sleep(100);
    }
    std::cout << i << " Iterations to build " << (ai.getResource("hasHouse") - houseCountStart) << " houses" << std::endl;
}
