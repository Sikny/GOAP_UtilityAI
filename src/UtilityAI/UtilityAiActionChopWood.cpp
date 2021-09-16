// Created by Quentin Pamart on 15/09/2021.

#include <cassert>
#include "UtilityAiActionChopWood.h"
#include "../World.h"

float UtilityAiActionChopWood::utility(const std::map<ActionEnum, int> &map) {
    const auto& it = map.find(hasWood);
    const auto& itStamina = map.find(hasStamina);
    assert(itStamina != map.end());
    assert(it != map.end());
    float eval = evalFunc(it->second, INVENTORY_WOOD_CAPACITY);
    if(itStamina->second < STAMINA_SPEND_COLLECT_WOOD) return 0;
    return eval;
}
