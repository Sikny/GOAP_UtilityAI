//
// Created by Antoine on 14/09/2021.
//

#pragma once
#include <map>
#include <string>
#include <vector>
#include "Action.h"

class GoapAI {

public:
    GoapAI();
    bool performBestActionPossible();
private:

    std::map<std::string, object> resources{};
    std::vector<Action*> actions{};


};
