// Created by Quentin Pamart on 15/09/2021.

#include <cassert>
#include "UtilityAiActionCreatePlank.h"
#include "../World.h"

float UtilityAiActionCreatePlank::utility(const std::map<std::string, int> &map) {
    const auto& itPlanksCount = map.find("hasPlank");
    const auto& itWoodCount = map.find("hasWood");
    const auto& itStamina = map.find("hasStamina");
    assert(itStamina != map.end());
    assert(itPlanksCount != map.end());
    assert(itWoodCount != map.end());
    float plankCountEval = evalFunc(itPlanksCount->second, INVENTORY_PLANKS_CAPACITY);
    if(itWoodCount->second < PLANK_WOOD_NEEDED) return 0;
    if(itStamina->second < STAMINA_SPEND_CREATE_PLANK) return 0;
    return plankCountEval;
}
