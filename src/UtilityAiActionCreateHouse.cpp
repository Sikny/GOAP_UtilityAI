// Created by Quentin Pamart on 15/09/2021.

#include <cassert>
#include "UtilityAiActionCreateHouse.h"

float UtilityAiActionCreateHouse::utility(const std::map<std::string, int> &map) {
    const auto& it = map.find("hasHouse");
    assert(it != map.end());
    float plankCountEval = (float) it->second / ;

    return plankCountEval;
}
