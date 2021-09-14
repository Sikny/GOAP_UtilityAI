//
// Created by Antoine on 14/09/2021.
//

#pragma once
#include <map>
#include <string>

class Action {


public:
    void AddEffect(const char* string);

    void AddPrecondition(const char* string);

    void performAction(const std::map<std::string,bool>&);

    bool canPerform(std::map<std::string, bool> map);
};
