// Created by Quentin Pamart on 15/09/2021.

#include <cassert>
#include "UtilityAiActionChopWood.h"
#include "World.h"

float UtilityAiActionChopWood::utility(const std::map<std::string, int> &map) {
    const auto& it = map.find("hasWood");
    assert(it != map.end());
    float eval = it->second >= HOUSE_PLANKS_NEEDED ? (float) it->second / HOUSE_PLANKS_NEEDED : 0;
    return eval;
}
