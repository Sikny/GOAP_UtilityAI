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

    bool canPerform(std::map<std::string, int> map);

private:
	std::map<std::string, int> preconditions;
	std::map<std::string, int> effects;
};
