// Created by Quentin Pamart on 15/09/2021.

#pragma once
#include "../Action.h"

class GoapAction : public Action{
public:
    explicit GoapAction(int cost, std::string desc);

    void AddPrecondition(const std::string& string, int value);

    bool canPerform(const std::map<std::string, int>& map) const;

    const std::map<std::string, int>& getPreconditions() const;
    int getCost() const;

private:
    int m_cost;
    std::map<std::string, int> m_preconditions;
};


