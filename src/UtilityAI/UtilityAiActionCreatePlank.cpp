// Created by Quentin Pamart on 15/09/2021.

#include <cassert>
#include "UtilityAiActionCreatePlank.h"
#include "../World.h"

float UtilityAiActionCreatePlank::utility(const std::map<std::string, int> &map) {
    const auto& itPlanksCount = map.find("hasPlank");
    const auto& itWoodCount = map.find("hasWood");
    assert(itPlanksCount != map.end());
    assert(itWoodCount != map.end());
    float plankCountEval = 1 - (float) itPlanksCount->second / INVENTORY_PLANKS_CAPACITY;
    if(itWoodCount->second < PLANK_WOOD_NEEDED) return 0;
    return plankCountEval;
}
