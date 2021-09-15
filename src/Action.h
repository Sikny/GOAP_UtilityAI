//
// Created by Antoine on 14/09/2021.
//

#pragma once
#include <map>
#include <string>

class Action {


public:
    void AddEffect(const std::string& string, int value);

    void AddPrecondition(const std::string& string, int value);

    void performAction(const std::map<std::string, int>&);

    bool canPerform(const std::map<std::string, int>& map);

    int getPrecondition(const std::string&) const;
    int getEffect(const std::string&) const;

    const std::map<std::string, int>& getPreconditions();
    const std::map<std::string, int>& getEffects();

private:
	std::map<std::string, int> preconditions;
	std::map<std::string, int> effects;
};
