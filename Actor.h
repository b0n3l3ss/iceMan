#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp


//class Actor : public GraphObject{
//public:
//	Actor();
//	// Makes Actors a pure virtual class
//	virtual void doesSomething() = 0;
//};

/// I dont think that we are going to need this class, I think 
/// that both the ice and the boulder can be derived straight 
/// from "GraphObject"


//class MapItems : GraphObject {
//public:
//	MapItems();
//};

// I got advice, should start w/ ice
// Should have different parent class
class Ice : public GraphObject {
public:
	// Proper Constructor made for Ice to construct GraphObject
	Ice(int x, int y): GraphObject(IID_ICE, x, y, right, 0.25, 3){
		this->setVisible(true);
	}
};

class MovingObject : public GraphObject {
protected:
	// Protected so both iceman and protestors can access their hitpoints
	int hitPoints;
public:
	// Constructor normal constructor for general Movingobj with HP parameter
	MovingObject(int hp, int ID, int x, int y, Direction d, float size, int depth)
		: GraphObject(ID, x, y, d, size, depth) { 
		hitPoints = hp;
	};
};

class IceMan : public MovingObject {
public:
	IceMan() : MovingObject(10, IID_PLAYER, 30, 60, right, 1, 0) { } ;

private:
	// These are things that are only in IceMan
	int numSquirts;
	int numSonar;
	int numGold;

};

#endif //ACTOR_H_
