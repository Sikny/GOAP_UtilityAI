//
// Created by Antoine on 14/09/2021.
//
#include "GOAP AI/GoapAI.h"
#include "GOAP AI/GoapAction.h"
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
    AI.setResource("hasStamina", 5);

    GoapAction* drinkWater = new GoapAction(2, "Recover Stamina");
    drinkWater->AddEffect("hasStamina", 4);

    GoapAction* chopWoodGoap = new GoapAction(3,"Chop wood");
    chopWoodGoap->AddPrecondition("hasStamina", 2);
    chopWoodGoap->AddEffect("hasWood", 3);
    chopWoodGoap->AddEffect("hasStamina", -2);

    GoapAction* createPlankGoap = new GoapAction(2,"Create plank");
    createPlankGoap->AddPrecondition("hasWood", 5);
    createPlankGoap->AddPrecondition("hasStamina", 3);
    createPlankGoap->AddEffect("hasPlank", 1);
    createPlankGoap->AddEffect("hasWood", -5);
    createPlankGoap->AddEffect("hasStamina", -3);

    GoapAction* createHouseGoap = new GoapAction(1,"Build house WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
    createHouseGoap->AddPrecondition("hasPlank", 26);
    createHouseGoap->AddPrecondition("hasStamina", 5);
    createHouseGoap->AddEffect("hasHouse", 1);
    createHouseGoap->AddEffect("hasPlank", -25);
    createHouseGoap->AddEffect("hasStamina", -5);

    AI.addAction(drinkWater);
    AI.addAction(chopWoodGoap);
    AI.addAction(createPlankGoap);
    AI.addAction(createHouseGoap);

    for(int i = 0 ; i < 100 ; ++i){
		AI.performBestActionPossible();
        AI.debug();
	}
/*
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
    std::cout << i << " Iterations to build " << (ai.getResource("hasHouse") - houseCountStart) << " houses" << std::endl;*/
}
