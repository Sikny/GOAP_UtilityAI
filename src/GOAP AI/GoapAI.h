//
// Created by Antoine on 14/09/2021.
//

#pragma once
#include <map>
#include <string>
#include <vector>
#include <stack>
#include <cassert>
#include "../Action.h"

class Action;

class GoapAI {

public:

    bool performBestActionPossible();
    void findActionsOfEffect(std::string effect, std::vector<std::tuple<Action*,int>>& compatibleActions) const;

    void setResource(const std::string&, int);
    void addAction(Action*);

private:

    std::map<std::string, int> resources{};
    std::map<std::string, int> tmpResources;
    std::vector<Action*> actions{};
    void getMissingPreconditions(const Action *action, std::map<std::string, int>& missingPreconditions) const;

    bool getActionsAndCost(Action *action, int *cost, std::stack<Action *> &stk) ;
    void mergeStack(std::stack<Action*>& s1, std::stack<Action*>& s2) const;
};
