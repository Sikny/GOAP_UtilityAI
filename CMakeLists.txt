cmake_minimum_required(VERSION 3.20)
project(GOAP_UtilityAI)

set(CMAKE_CXX_STANDARD 20)

add_executable(GOAP_UtilityAI src/Action.cpp src/Action.h src/main.cpp "src/GOAP AI/GoapAI.cpp" "src/GOAP AI/GoapAI.h" "src/GOAP AI/GoapAction.cpp" "src/GOAP AI/GoapAction.h" src/UtilityAI/UtilityAiAction.cpp src/UtilityAI/UtilityAiAction.h src/UtilityAI/UtilityAiActionChopWood.cpp src/UtilityAI/UtilityAiActionChopWood.h src/UtilityAI/UtilityAi.cpp src/UtilityAI/UtilityAi.h src/World.h src/UtilityAI/UtilityAiActionCreatePlank.cpp src/UtilityAI/UtilityAiActionCreatePlank.h src/UtilityAI/UtilityAiActionCreateHouse.cpp src/UtilityAI/UtilityAiActionCreateHouse.h src/UtilityAI/FunctionsHelper.h src/UtilityAI/UtilityAiActionDrinkWater.cpp src/UtilityAI/UtilityAiActionDrinkWater.h src/UtilityAI/UtilityAiActionCollectStone.cpp src/UtilityAI/UtilityAiActionCollectStone.h src/UtilityAI/UtilityAiActionCreateWall.cpp src/UtilityAI/UtilityAiActionCreateWall.h)
