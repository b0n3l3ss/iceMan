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
	void removeBlocksVert(int x, int y);
private:
	IceMan* player;
	Ice* ice[64][64];
	
};

#endif //STUDENTWORLD_H_
