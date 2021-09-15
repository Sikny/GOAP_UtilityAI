//
// Created by Antoine on 14/09/2021.
//

#pragma once
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <cassert>
#include "Action.h"

class GoapAI {

public:
    GoapAI();
    bool performBestActionPossible(Action* action);
private:

    std::map<std::string, int> resources{};
    std::vector<Action*> actions{};


};
