//
// Created by Antoine on 14/09/2021.
//
#include "GOAP AI/GoapAI.h"
#include "GOAP AI/GoapAction.h"
#include "UtilityAI/UtilityAi.h"
#include "UtilityAI/UtilityAiActionChopWood.h"
#include "UtilityAI/UtilityAiActionCreatePlank.h"
#include "UtilityAI/UtilityAiActionCreateHouse.h"
#include "UtilityAI/UtilityAiActionDrinkWater.h"
#include "World.h"
#include "UtilityAI/FunctionsHelper.h"
#include "UtilityAI/UtilityAiActionCollectStone.h"
#include "UtilityAI/UtilityAiActionCreateWall.h"
#include <windows.h>
#include <iostream>

int main(int argc, char** argv){
    GoapAI AI;

    std::cout << "GOAP AI" << std::endl;
    AI.setResource(hasHouse, rand() % 11 + 0);
    AI.setResource(hasPlank, rand() % 11 + 0);
    AI.setResource(hasWood, rand() % 11 + 0);
    AI.setResource(hasStamina, 5);

    GoapAction* drinkWater = new GoapAction(2, "Recover Stamina");
    drinkWater->AddEffect(hasStamina, 4);

    GoapAction* chopWoodGoap = new GoapAction(3,"Chop wood");
    chopWoodGoap->AddPrecondition(hasStamina, STAMINA_SPEND_COLLECT_WOOD);
    chopWoodGoap->AddEffect(hasWood, 3);
    chopWoodGoap->AddEffect(hasStamina, -STAMINA_SPEND_COLLECT_WOOD);

    GoapAction* createPlankGoap = new GoapAction(2,"Create plank");
    createPlankGoap->AddPrecondition(hasWood, PLANK_WOOD_NEEDED);
    createPlankGoap->AddPrecondition(hasStamina, STAMINA_SPEND_CREATE_PLANK);
    createPlankGoap->AddEffect(hasPlank, 1);
    createPlankGoap->AddEffect(hasWood, -PLANK_WOOD_NEEDED);
    createPlankGoap->AddEffect(hasStamina, -STAMINA_SPEND_CREATE_PLANK);

    GoapAction* createHouseGoap = new GoapAction(1,"Build house WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO");
    createHouseGoap->AddPrecondition(hasPlank, HOUSE_PLANKS_NEEDED);
    createHouseGoap->AddPrecondition(hasStamina, STAMINA_SPEND_CREATE_HOUSE);
    createHouseGoap->AddEffect(hasHouse, 1);
    createHouseGoap->AddEffect(hasPlank, -HOUSE_PLANKS_NEEDED);
    createHouseGoap->AddEffect(hasStamina, -STAMINA_SPEND_CREATE_HOUSE);

    AI.addAction(drinkWater);
    AI.addAction(chopWoodGoap);
    AI.addAction(createPlankGoap);
    AI.addAction(createHouseGoap);

    for(int i = 0 ; i < 100 ; ++i){
		AI.performBestActionPossible();
        AI.debug();
	}

    std::cout << "UTILITY AI" << std::endl;

    UtilityAi ai;
    std::srand(time(nullptr));
    ai.setResource(hasWood, rand() % 11 + 0);
    ai.setResource(hasPlank, rand() % 11 + 0);
    ai.setResource(hasHouse, rand() % 11 + 0);
    ai.setResource(hasRock, rand() % 11 + 0);
    ai.setResource(hasWall, rand() % 11 + 0);
    ai.setResource(hasStamina, 5);
    int houseCountStart = ai.getResource(hasHouse);
    ai.debug();

    UtilityAiAction* drinkWaterUtilityAi = new UtilityAiActionDrinkWater("Recover Stamina", ratioSqrt);
    drinkWaterUtilityAi->AddEffect(hasStamina, 4);
    ai.addAction(drinkWaterUtilityAi);

    UtilityAiAction* chopWood = new UtilityAiActionChopWood("Chop wood", ratioSqrt);
    chopWood->AddEffect(hasWood, 3);
    chopWood->AddEffect(hasStamina, -STAMINA_SPEND_COLLECT_WOOD);
    ai.addAction(chopWood);

    UtilityAiAction* mineStone = new UtilityAiActionCollectStone("Mine stone", ratioSqrt);
    mineStone->AddEffect(hasRock, 4);
    mineStone->AddEffect(hasStamina, -STAMINA_SPEND_COLLECT_ROCK);
    ai.addAction(mineStone);

    UtilityAiAction* createPlank = new UtilityAiActionCreatePlank("Create plank", ratioSqrt);
    createPlank->AddEffect(hasPlank, 1);
    createPlank->AddEffect(hasWood, -PLANK_WOOD_NEEDED);
    createPlank->AddEffect(hasStamina, -STAMINA_SPEND_CREATE_PLANK);
    ai.addAction(createPlank);

    UtilityAiAction* createWall = new UtilityAiActionCreateWall("Create wall", ratioSqrt);
    createWall->AddEffect(hasWall, 1);
    createWall->AddEffect(hasRock, -WALL_STONE_NEEDED);
    createWall->AddEffect(hasStamina, -STAMINA_SPEND_CREATE_WALL);
    ai.addAction(createWall);

    UtilityAiAction* createHouse = new UtilityAiActionCreateHouse("Build house");
    createHouse->AddEffect(hasHouse, 1);
    createHouse->AddEffect(hasPlank, -HOUSE_PLANKS_NEEDED);
    createHouse->AddEffect(hasWall, -HOUSE_WALLS_NEEDED);
    createHouse->AddEffect(hasStamina, -STAMINA_SPEND_CREATE_HOUSE);
    ai.addAction(createHouse);

    int i = 0;
    while(i++ < 99 && (ai.getResource(hasHouse) - houseCountStart) < 2){
        ai.tick();
        ai.debug();
        Sleep(100);
    }
    std::cout << i << " Iterations to build " << (ai.getResource(hasHouse) - houseCountStart) << " houses" << std::endl;
}
