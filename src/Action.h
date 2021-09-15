//
// Created by Antoine on 14/09/2021.
//

#pragma once
#include <map>
#include <string>

class Action {


public:
    void AddEffect(const std::string* string,object value);

    void AddPrecondition(const std::string* string,object value);

    void performAction(const std::map<std::string,object>&);

    bool canPerform(std::map<std::string, object> map);

private:
	std::map<std::string,object> preconditions;
	std::map<std::string,object> effects;
};
