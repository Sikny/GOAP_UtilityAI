#pragma once
#define INVENTORY_PLANKS_CAPACITY 50
#define INVENTORY_WOOD_CAPACITY 20
#define HOUSE_PLANKS_NEEDED 25
#define PLANK_WOOD_NEEDED 5

struct World{
    //std::unordered_map<Resource, unsigned int> worldResources;  // todo refactor here
    unsigned int numberHouse = 0;
};