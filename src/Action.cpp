//
// Created by Antoine on 14/09/2021.
//

#include "Action.h"

void Action::AddEffect(const std::string& string, int value) {
	effects[string] = value;
}

void Action::AddPrecondition(const std::string& string, int value) {
	preconditions[string] = value;
}

void Action::performAction(const std::map<std::string, int>&) {

}

bool Action::canPerform(std::map<std::string, int> map) {
	for(int i = 0; i < preconditions.size(); ++i){
		//preconditions.at(i).first, on verifie avec map si la condition du second est bonne, si oui on
	}
    return false;
}
