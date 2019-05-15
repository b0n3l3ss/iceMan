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
		for (int j = 0; j < 64; ++j){
			ice[i][j] = new Ice(i, j);
			if(j >= 60)	//sets top row to clear
				ice[i][j]->setVisible(false);
			// This makes the initial cavern
			if (i < 34 && i >= 30 && j > 4)
				ice[i][j]->setVisible(false);
		}
	}
	player = new IceMan(this/*, ice*/);


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

void StudentWorld::removeBlocks(int x, int y)
{
	ice[x][y-64]->setVisible(false);
	ice[x][y-63]->setVisible(false);
	ice[x][y-62]->setVisible(false);
	ice[x][y-61]->setVisible(false);
	
	ice[x+1][y-64]->setVisible(false);
	ice[x+1][y-63]->setVisible(false);
	ice[x+1][y-62]->setVisible(false);
	ice[x+1][y-61]->setVisible(false);
	
	ice[x+2][y-64]->setVisible(false);
	ice[x+2][y-63]->setVisible(false);
	ice[x+2][y-62]->setVisible(false);
	ice[x+2][y-61]->setVisible(false);
	
	ice[x+3][y-64]->setVisible(false);
	ice[x+3][y-63]->setVisible(false);
	ice[x+3][y-62]->setVisible(false);
	ice[x+3][y-61]->setVisible(false);
	
}
