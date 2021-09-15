//
// Created by Antoine on 14/09/2021.
//

#include <cassert>
#include "Action.h"

void Action::AddEffect(const std::string& string, int value) {
	effects[string] = value;
}

void Action::AddPrecondition(const std::string& string, int value) {
	preconditions[string] = value;
}

void Action::performAction(const std::map<std::string, int>&) {

}

bool Action::canPerform(const std::map<std::string, int>& map) {
    for(const auto& precondition : preconditions){
        const std::string& key = precondition.first;
        const auto& mapIt = map.find(key);
        assert(mapIt != map.end());
        if(mapIt == map.end())
            return false;
        if(precondition.second < mapIt->second)
            return false;
    }
    return true;
}
