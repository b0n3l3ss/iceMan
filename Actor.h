#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
//#include "StudentWorld.h"
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;

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

class Actor : public GraphObject {
public:
	Actor(int ID, int x, int y, Direction d, double size, int depth)
	: GraphObject(ID, x, y, d, size, depth) { }
	virtual void doSomething() = 0;
	virtual ~Actor() { }
};

class Ice : public Actor {
public:
	// Proper Constructor made for Ice to construct GraphObject
	Ice(int x, int y): Actor(IID_ICE, x, y, right, 0.25, 3){
		this->setVisible(true);
	}
	void doSomething() { }
	~Ice() { }
};

class MovingObject : public Actor {
protected:
	// Protected so both iceman and protestors can access their hitpoints
	int hitPoints;
	StudentWorld* world;
	
public:
	// Constructor normal constructor for general Moving obj with HP parameter
	MovingObject(int hp, int ID, int x, int y, Direction d, float size, int depth, StudentWorld* w)
		: Actor(ID, x, y, d, size, depth) { 
		hitPoints = hp;
			world = w;
	};
	// All objects other than ice do nothing
	// Pure Virtual fct
	virtual void doSomething() = 0;
	//virtual StudentWorld* getWorld();
	virtual ~MovingObject() { }
};

class IceMan : public MovingObject {
public:
	IceMan(StudentWorld* w) : MovingObject(10, IID_PLAYER, 30, 60, right, 1, 0, w) {
		this->setVisible(true);
	};
	// Wasn't sure if I needed to re-declare this, even though it is already
	// in the MovingObject class
	void doSomething();
	StudentWorld* getWorld();
	
	~IceMan() { }
	
private:
	// These are things that are only in IceMan
	int numSquirts;
	int numSonar;
	int numGold;
};

#endif //ACTOR_H_
