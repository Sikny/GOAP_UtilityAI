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
    std::map<ActionEnum, int> tmpResources;
	std::vector<GoapAction*> m_actions{};
	std::vector<ActionEnum> m_actionEnums{};
	GoapAction* m_goal;
    void getMissingPreconditions(const GoapAction *action, std::map<ActionEnum, int>& missingPreconditions) const;

    bool planActions(std::vector<ActionEnum>& action) ;
    void mergeStack(std::stack<GoapAction*>& s1, std::stack<GoapAction*>& s2) const;
	std::map<ActionEnum, bool>* convertConditionsToBool(const std::map<ActionEnum, int>* map) const;

	GoapAction* getActionForActionEnum(ActionEnum actionEnum) const;
};
