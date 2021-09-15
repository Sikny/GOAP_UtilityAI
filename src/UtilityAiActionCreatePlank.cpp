// Created by Quentin Pamart on 15/09/2021.

#include <cassert>
#include "UtilityAiActionCreatePlank.h"
#include "World.h"

float UtilityAiActionCreatePlank::utility(const std::map<std::string, int> &map) {
    const auto& it = map.find("hasPlank");
    assert(it != map.end());
    float plankCountEval = (float) it->second / INVENTORY_PLANKS_CAPACITY;

    return plankCountEval;
}
