// Created by Quentin Pamart on 16/09/2021.

#include <cassert>
#include "UtilityAiActionCollectStone.h"
#include "../World.h"

float UtilityAiActionCollectStone::utility(const std::map<ActionEnum, int> &map) {
    const auto& it = map.find(hasRock);
    const auto& itStamina = map.find(hasStamina);
    assert(itStamina != map.end());
    assert(it != map.end());
    float eval = evalFunc(it->second, INVENTORY_STONE_CAPACITY);
    if(itStamina->second < STAMINA_SPEND_COLLECT_ROCK) return 0;
    return eval;
}
