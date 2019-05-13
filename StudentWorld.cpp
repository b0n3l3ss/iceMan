#include "StudentWorld.h"
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp

int StudentWorld::init() {
	//Printed out ice with 2d array
	Ice* temp[64][60];
	for (int i = 0; i < 64; ++i) {
		for (int j = 0; j < 60; ++j){
			temp[i][j] = new Ice(i, j);
		}
	}
	
	// Unique pointer not pringing out ice
//	unique_ptr<Ice> temp {make_unique<Ice>(0,0)};
//	auto temp2 = make_unique<Ice>(30,30);
//	vector<unique_ptr<Ice>> iceVec;
//	for (int i = 0; i < 64; ++i) {
//		for (int j = 0; j < 60; ++j){
//			iceVec.push_back({make_unique<Ice>(i, j)});
//			iceVec[(60 * i) + j]->setVisible(true);
//		}
//	}
	return GWSTATUS_CONTINUE_GAME;
}
