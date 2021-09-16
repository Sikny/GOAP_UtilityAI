//
// Created by Antoine on 14/09/2021.
//
#include "GOAP AI/GoapAI.h"
#include "UtilityAI/UtilityAi.h"
#include "UtilityAI/UtilityAiActionChopWood.h"
#include "UtilityAI/UtilityAiActionCreatePlank.h"
#include "UtilityAI/UtilityAiActionCreateHouse.h"
#include "World.h"
#include <windows.h>
#include <iostream>

int main(int argc, char** argv){
    GoapAI AI;

    std::cout << "GOAP AI" << std::endl;
    AI.setResource("hasHouse", rand() % 11 + 0);
    AI.setResource("hasPlank", rand() % 11 + 0);
    AI.setResource("hasWood", rand() % 11 + 0);

    Action* chopWoodGoap = new Action(3,"Chop wood");
    chopWoodGoap->AddEffect("hasWood", 3);

    Action* createPlankGoap = new Action(2,"Create plank");
    createPlankGoap->AddPrecondition("hasWood", 5);
    createPlankGoap->AddEffect("hasPlank", 1);
    createPlankGoap->AddEffect("hasWood", -5);

    Action* createHouseGoap = new Action(1,"Build house WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
    createHouseGoap->AddPrecondition("hasPlank", 25);
    createHouseGoap->AddEffect("hasHouse", 1);
    createHouseGoap->AddEffect("hasPlank", -25);

    AI.addAction(chopWoodGoap);
    AI.addAction(createPlankGoap);
    AI.addAction(createHouseGoap);

    for(int i = 0 ; i < 100 ; ++i){
		AI.performBestActionPossible();
	}

    std::cout << "UTILITY AI" << std::endl;

    UtilityAi ai;
    std::srand(time(nullptr));
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
