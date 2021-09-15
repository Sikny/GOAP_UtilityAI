//
// Created by Antoine on 14/09/2021.
//

#pragma once
#include <map>
#include <string>

class Action {


public:
	explicit Action(int cost, const std::string& desc);
    void AddEffect(const std::string& string, int value);

    void AddPrecondition(const std::string& string, int value);

    void performAction(std::map<std::string, int>&);

    bool canPerform(const std::map<std::string, int>& map);

    int getPrecondition(const std::string&) const;
	int getEffect(const std::string&) const;
	int getCost() const;

    const std::map<std::string, int>& getPreconditions();
    const std::map<std::string, int>& getEffects();

private:
	int m_cost;
	std::string m_description;
	std::map<std::string, int> m_preconditions;
	std::map<std::string, int> m_effects;
};
