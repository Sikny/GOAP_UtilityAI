// Created by Quentin Pamart on 15/09/2021.

#pragma once
#include "../Action.h"
#include "../ActionEnum.h"

class GoapAction : public Action{
public:
    explicit GoapAction(int cost, std::string desc);

    void AddPrecondition(const ActionEnum& string, int value);

    bool canPerform(const std::map<ActionEnum, int>& map) const;

    const std::map<ActionEnum, int>& getPreconditions() const;
    int getCost() const;

private:
    int m_cost;
    std::map<ActionEnum, int> m_preconditions;
};


