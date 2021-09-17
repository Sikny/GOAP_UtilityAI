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
	void setGoal(GoapAction* goal);

    void debug();

private:

    std::map<ActionEnum, int> resources{};
	std::vector<GoapAction*> m_actions{};
	GoapAction* m_goal;

    GoapAction* planActions();
    void mergeStack(std::stack<GoapAction*>& s1, std::stack<GoapAction*>& s2) const;
};
