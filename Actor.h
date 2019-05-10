#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp


class Actor : public GraphObject {
private:
	int imageID;
	int startX;
	int startY;
	Direction startDirection;
	float size;
	unsigned int depth;
public:
	 Actor (int imID, int strtX, int strtY, Direction strt, float s, unsigned int dpth);
};

// I got advice, should start w/ ice
// Should have different parent class
class Ice : public Actor {
private: 

public:

};

#endif // ACTOR_H_
