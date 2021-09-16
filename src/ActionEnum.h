//
// Created by Marine on 16/09/2021.
//
#pragma once

enum ActionEnum {hasWood,hasStamina,hasPlank,hasHouse,hasRock,hasWall};

const std::map<ActionEnum, std::string> actionStrings = {
    std::pair(hasWood, "Wood"),
    std::pair(hasStamina, "Stamina"),
    std::pair(hasPlank, "Plank"),
    std::pair(hasHouse, "House"),
    std::pair(hasRock, "Rock"),
    std::pair(hasWall, "Wall"),

};
