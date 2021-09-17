// Created by Quentin Pamart on 17/09/2021.

#include <cassert>
#include "UtilityAiActionCollectResource.h"

float UtilityAiActionCollectResource::utility(const std::map<ActionEnum, int> &map) {
    const auto& it = map.find(resource);
    assert(it != map.end());
    return evalFunc(it->second, resourceMax);
}
