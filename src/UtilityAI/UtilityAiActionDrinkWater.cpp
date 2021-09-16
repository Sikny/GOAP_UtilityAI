// Created by Quentin Pamart on 16/09/2021.

#include <cassert>
#include "UtilityAiActionDrinkWater.h"
#include "../World.h"

float UtilityAiActionDrinkWater::utility(const std::map<ActionEnum, int> &map) {
    const auto& it = map.find(hasStamina);
    assert(it != map.end());
    return evalFunc(it->second, INVENTORY_STAMINA_CAPACITY);
}