// Created by Quentin Pamart on 15/09/2021.

#include <cassert>
#include "UtilityAiActionCreateHouse.h"
#include "../World.h"

float UtilityAiActionCreateHouse::utility(const std::map<std::string, int> &map) {
    const auto& it = map.find("hasPlank");
    assert(it != map.end());
    float eval = it->second >= HOUSE_PLANKS_NEEDED ? 1 : 0;

    return eval;
}
