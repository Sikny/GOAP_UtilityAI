//
// Created by Marine on 16/09/2021.
//
#pragma once
#include "../ActionEnum.h"
#include <vector>
#include <map>

class GOAPTreeNode {
public:
	GOAPTreeNode(ActionEnum action, int cost, const std::map<ActionEnum,bool>* preconditions, const std::map<ActionEnum,bool>* effects, const std::map<ActionEnum,bool>* currentState,
				 GOAPTreeNode* parent = nullptr);
	int getDistanceToGoal() const;
	void addChild(GOAPTreeNode& child);
	std::vector<GOAPTreeNode&> getChildren() const;
	ActionEnum getActionEnum() const;
private:
	ActionEnum m_action;//L'action correspondante au node
	int m_cost;//Le cout de l'action
	GOAPTreeNode& m_parent; // le noeud parent
	std::vector<GOAPTreeNode&> m_children; // la liste des noeuds descendant du noeud actuel

	std::map<ActionEnum,bool> m_currentState;//l'état des conditions de l'objectif si cette tache est réalisée
	std::map<ActionEnum,bool>* m_preconditions;//les conditions requises pour la réalisation de cette action
	std::map<ActionEnum,bool>* m_effects;// les effets réalisés en cas de réussite
};
