#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
#include <vector>
#include <memory>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
	StudentWorld(std::string assetDir)
		: GameWorld(assetDir) {

	}

	virtual int init();

	virtual int move();

	virtual void cleanUp();
	
	void removeBlocks(int x, int y);
	
	void removeBoulderIce(int x, int y);
	
	bool isBoulderThereR(int, int);
	bool isBoulderThereL(int, int);
	bool isBoulderThereU(int, int);
	bool isBoulderThereD(int, int);
	
	bool isIceVisable(int, int);
	
	~StudentWorld();
private:
	IceMan* player = nullptr;
	Ice* ice[64][64] = {nullptr};
	//Boulder* bould = nullptr;
	//Boulder* bould2 = nullptr;
	// Im fine keeping the boulders as their own individual pointers
	// for testing purpouses, but Im going to start putting them in a 
	// vector
	std::vector<Actor*> gameActors;
	int bouldNum = 20; //floor((getLevel() / 2) + 2);
	void createBoulder();
	void checkForObject(int&, int&);
	
	void createIce();

	void updateScore();	//updates the scoreboard on the top of the screen
	std::string formatScoreBoard(int, int, int, int, int, int, int, int);
};

#endif //STUDENTWORLD_H_
