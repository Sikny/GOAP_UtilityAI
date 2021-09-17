// Created by Quentin Pamart on 16/09/2021.

#include <cassert>
#include "UtilityAiActionCreateWall.h"
#include "../World.h"

float UtilityAiActionCreateWall::utility(const std::map<ActionEnum, int> &map) {
    const auto& itWallsCount = map.find(hasWall);
    const auto& itStoneCount = map.find(hasRock);
    const auto& itStamina = map.find(hasStamina);
    assert(itStamina != map.end());
    assert(itWallsCount != map.end());
    assert(itStoneCount != map.end());
    float plankCountEval = evalFunc(itWallsCount->second, INVENTORY_WALLS_CAPACITY);
    if(itStoneCount->second < WALL_STONE_NEEDED) return 0;
    if(itStamina->second < STAMINA_SPEND_CREATE_WALL) return 0;
    return plankCountEval;}