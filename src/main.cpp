//
// Created by Antoine on 14/09/2021.
//
#include "GoapAI.h"

int main(int argc, char** argv){
    GoapAI AI;

	for(int i = 0 ; i < 100 ; ++i){
		AI.performBestActionPossible();
	}
}
