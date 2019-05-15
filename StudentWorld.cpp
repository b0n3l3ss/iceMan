#include "StudentWorld.h"
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp

int StudentWorld::init() {
	// Create & print out ice with 2d array
	for (int i = 0; i < 64; ++i) {
		for (int j = 0; j < 60; ++j){
			ice[i][j] = new Ice(i, j);
			// This makes the initial cavern
			if (i < 34 && i >= 30 && j > 4)
				ice[i][j]->setVisible(false);
		}
	}
	player = new IceMan(this);


	return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move() {
// This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
// Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
	
	player->doSomething();


	decLives();
	return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp() {

}
