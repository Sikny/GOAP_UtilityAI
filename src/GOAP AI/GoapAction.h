// Created by Quentin Pamart on 15/09/2021.

#pragma once
#include "../Action.h"
#include "../ActionEnum.h"

class GoapAction : public Action{
public:
    GoapAction(std::string desc, int cost, std::map<ActionEnum, int>* preconditions, std::map<ActionEnum, int>& effects, std::map<ActionEnum, bool> currentState, GoapAction* parent);

    void AddPrecondition(const ActionEnum& string, int value);

    [[nodiscard]] std::map<ActionEnum, int>* getPreconditions();
    int getCost() const;

    void AddChild(GoapAction action);
    [[nodiscard]] std::vector<GoapAction*>* getChildren()const;
     GoapAction* getParent()const;

    int getDistanceToGoal() const;
    std::map<ActionEnum, bool> getCurrentState();
    bool canPerform(const std::map<ActionEnum, int>& map) const;

private:
    int m_cost;
    std::map<ActionEnum, int> m_preconditions;
    std::map<ActionEnum, int> m_boolPreconditions;
    std::map<ActionEnum, bool> m_currentState;//l'état des conditions de l'objectif si cette tache est réalisée
    GoapAction* m_parent; // le noeud parent
    std::vector<GoapAction*>* m_children{}; // la liste des noeuds descendant du noeud actuel
};