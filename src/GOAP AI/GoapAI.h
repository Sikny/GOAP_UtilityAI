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

class GoapAction;

class GoapAI {

public:

    bool performBestActionPossible();
    void findActionsOfEffect(std::string effect, std::vector<std::tuple<GoapAction*,int>>& compatibleActions) const;

    void setResource(const std::string&, int);
    void addAction(GoapAction*);

    void debug();

private:

    std::map<std::string, int> resources{};
    std::map<std::string, int> tmpResources;
    std::vector<GoapAction*> actions{};
    void getMissingPreconditions(const GoapAction *action, std::map<std::string, int>& missingPreconditions) const;

    bool getActionsAndCost(GoapAction *action, int *cost, std::stack<GoapAction *> &stk) ;
    void mergeStack(std::stack<GoapAction*>& s1, std::stack<GoapAction*>& s2) const;
};
