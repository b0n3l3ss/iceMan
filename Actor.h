#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
//#include "StudentWorld.h"
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp

class StudentWorld;

// Changed this class so that all of the classes have acess to the 
// Student world

class Actor : public GraphObject {
protected:
	// That way all of the objects have acess to world for their
	// doSomething methods
	StudentWorld* world = nullptr;
public:
	Actor(int ID, int x, int y, Direction d, double size, int depth, StudentWorld* w)
	: GraphObject(ID, x, y, d, size, depth) {
		world = w;
	}
	virtual void doSomething() = 0;
	virtual StudentWorld* getWorld();
	virtual ~Actor() { }
};

class Ice : public Actor {
public:
	// Proper Constructor made for Ice to construct GraphObject
	Ice(int x, int y): Actor(IID_ICE, x, y, right, 0.25, 3, nullptr){
		this->setVisible(true);
	}
	void doSomething() { }
	~Ice() { }
};

class MovingObject : public Actor {
protected:
	// Protected so both iceman and protestors can access their hitpoints
	int hitPoints;
	
public:
	// Constructor normal constructor for general Moving obj with HP parameter
	MovingObject(int hp, int ID, int x, int y, Direction d, float size, int depth, StudentWorld* w)
		: Actor(ID, x, y, d, size, depth, w) { 
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
		numSquirts = 5;
		numSonar = 1;
		numGold = 0;
		numOil = 0;
	};
	// Wasn't sure if I needed to re-declare this, even though it is already
	// in the MovingObject class
	void doSomething();
	int getHitPoints() const;
	int getSquirts() const;
	int getBarrels() const;
	int getSonar() const;
	int getGold() const;

	void incOil();
	void incGold();
	
	void makeHimDead();
	
	~IceMan() { }
	
private:
	// These are things that are only in IceMan
	int numSquirts;
	int numSonar;
	int numGold;
	int numOil;
};

class MapObject : public Actor {
protected:
	StudentWorld* world;
public:
	// All of the Map objects start out with a size of one, 
	// but everything else is specific to each MapObject
	MapObject(int ID, int x, int y, Direction d, int depth, StudentWorld* w)
		: Actor(ID, x, y, d, 1, depth, w) { };
	virtual ~MapObject() { };
	
	// Pure virtual class
	virtual void doSomething() = 0;
	
};

class Boulder : public MapObject {
private:
	// A bool to tell whether the boulder has fallen yet
	int m_waitingTime = 0;
	bool hasFallen;
public:
	Boulder(int x, int y, StudentWorld* w) : MapObject(IID_BOULDER, x, y, down, 1, w){
		setVisible(true);
		hasFallen = false;
	};
	virtual ~Boulder() { };
	virtual void doSomething();
	// Returns hasFallen
	virtual bool isFalling();
	bool isStable();
	bool doneWaiting();
};

class Gold : public MapObject {
private:
	// This is to decide if the gold can be picked up by either Iceman or 
	// one of the protestors as a bribe. It cannot be both, which I think
	// might make things a bit easier
	bool isBribe;
	void turnVisible();
public:
	Gold(int x, int y, StudentWorld* w) : MapObject(IID_GOLD, x, y, right, 2, w) {
		setVisible(false);
		isBribe = false;
	}
	bool isBribeState() const;
	void updateisBribeState(bool update);
	void doSomething();
	virtual ~Gold() {
		world = nullptr;
	}
};

class OilBarrel : public MapObject {
private:

public:
	OilBarrel(int x, int y, StudentWorld* w) : MapObject(IID_BARREL, x, y, right, 2, w) {
		setVisible(true);
	};
	virtual ~OilBarrel() { };
	void doSomething();
	
};

#endif //ACTOR_H_
