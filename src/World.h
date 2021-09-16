#pragma once
#define INVENTORY_PLANKS_CAPACITY 50
#define INVENTORY_WOOD_CAPACITY 20
#define INVENTORY_STAMINA_CAPACITY 30
#define INVENTORY_STONE_CAPACITY 20
#define INVENTORY_WALLS_CAPACITY 50
#define HOUSE_PLANKS_NEEDED 8
#define HOUSE_WALLS_NEEDED 4
#define PLANK_WOOD_NEEDED 5
#define WALL_STONE_NEEDED 8
#define STAMINA_SPEND_COLLECT_WOOD 2
#define STAMINA_SPEND_COLLECT_ROCK 3
#define STAMINA_SPEND_CREATE_PLANK 3
#define STAMINA_SPEND_CREATE_WALL 4
#define STAMINA_SPEND_CREATE_HOUSE 5

enum Resource {
    Wood,
    Plank,
    House
};

struct World{
    //std::unordered_map<Resource, unsigned int> worldResources;  // todo refactor here
    unsigned int numberHouse = 0;
};