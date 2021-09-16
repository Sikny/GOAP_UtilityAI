// Created by Quentin Pamart on 15/09/2021.

#include <cassert>
#include "UtilityAiActionCreateHouse.h"
#include "../World.h"

float UtilityAiActionCreateHouse::utility(const std::map<std::string, int> &map) {
    const auto& itPlankCount = map.find("hasPlank");
    const auto& itWallCount = map.find("hasWall");
    const auto& itStamina = map.find("hasStamina");
    assert(itStamina != map.end());
    assert(itPlankCount != map.end());
    if(itStamina->second < STAMINA_SPEND_CREATE_HOUSE) return 0;
    return (float) (itPlankCount->second >= HOUSE_PLANKS_NEEDED ? (itWallCount->second >= HOUSE_WALLS_NEEDED) ? 1 : 0 : 0);
}
