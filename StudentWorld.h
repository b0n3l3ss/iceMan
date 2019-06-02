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
	void updateItemCount();
	bool isBoulderThereR(int, int);
	bool isBoulderThereL(int, int);
	bool isBoulderThereU(int, int);
	bool isBoulderThereD(int, int);
	void isMapObjectThere(int, int);
	bool isIceVisable(int, int, Actor::Direction);
	void dropGold(int, int);
	void createSquirt(int, int, Actor::Direction);
	void checkSquirtRadius(int, int, int);
	void useSonar();
	void pickUpSonar(int);
	bool checkInitialSquirt(int, int);
	int sonarTimeMax();
	int waterPoolTimeMax();
	void createWaterPool();
	void pickUpWaterPool(int pos);
	void createSonarOrWater();
	bool isThereIce(int, int);
	void createRegProtestor();
	bool isIceManThere(int, int);
	
	int findRadius(int);
	
	~StudentWorld();
	
private:
	IceMan* player = nullptr;
	Ice* ice[64][64] = {nullptr};
	std::vector<Actor*> gameActors;
	int bouldNum;
	int goldNum;
	int oilNum;
	void checkForObject(int&, int&);
	void createBoulder();
	void createIce();
	void createGold();
	void createOil();
	void createSonar();
	
	void updateScore();	//updates the scoreboard on the top of the screen
	std::string formatScoreBoard(int, int, int, int, int, int, int, int);
};

#endif //STUDENTWORLD_H_
