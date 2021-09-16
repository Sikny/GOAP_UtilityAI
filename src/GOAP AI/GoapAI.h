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
#include "../ActionEnum.h"

class GoapAction;

class GoapAI {

public:

    bool performBestActionPossible();
    void findActionsOfEffect(ActionEnum effect, std::vector<std::tuple<GoapAction*,int>>& compatibleActions) const;

    void setResource(const ActionEnum&, int);
    void addAction(GoapAction*);

    void debug();

private:

    std::map<ActionEnum, int> resources{};
    std::map<ActionEnum, int> tmpResources;
    std::vector<GoapAction*> actions{};
    void getMissingPreconditions(const GoapAction *action, std::map<ActionEnum, int>& missingPreconditions) const;

    bool getActionsAndCost(GoapAction *action, int *cost, std::stack<GoapAction *> &stk) ;
    void mergeStack(std::stack<GoapAction*>& s1, std::stack<GoapAction*>& s2) const;
};
