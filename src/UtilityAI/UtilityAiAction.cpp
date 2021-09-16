// Created by Quentin Pamart on 15/09/2021.

#include "UtilityAiAction.h"
#include <utility>
#include <cassert>

UtilityAiAction::UtilityAiAction(std::string desc, float (*func)(int, int)) : Action(std::move(desc)), evalFunc(func){

}
