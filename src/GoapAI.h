//
// Created by Antoine on 14/09/2021.
//

#pragma once
#include <map>
#include <string>
#include <vector>

class Action;

class GoapAI {

public:
    GoapAI();
    bool performBestActionPossible();

    void setResource(const std::string&, int);
private:

    std::map<std::string, int> resources{};
    std::vector<Action*> actions{};


};
