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

class Action;

class GoapAI {

public:

    bool performBestActionPossible(Action* action);

    void setResource(const std::string&, int);
    void addAction(Action*);

private:

    std::map<std::string, int> resources{};
    std::vector<Action*> actions{};


};
