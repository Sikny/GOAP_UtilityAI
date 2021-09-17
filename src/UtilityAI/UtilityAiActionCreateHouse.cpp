// Created by Quentin Pamart on 15/09/2021.

#include <cassert>
#include "UtilityAiActionCreateHouse.h"
#include "../World.h"

float UtilityAiActionCreateHouse::utility(const std::map<ActionEnum, int> &map) {
    const auto& itPlankCount = map.find(hasPlank);
    const auto& itWallCount = map.find(hasWall);
    assert(itPlankCount != map.end());
    return (float) (itPlankCount->second >= HOUSE_PLANKS_NEEDED ? (itWallCount->second >= HOUSE_WALLS_NEEDED) ? 1 : 0 : 0);
}
