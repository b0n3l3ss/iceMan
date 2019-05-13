#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp


class Actor : public GraphObject{
public:
	Actor();
	// Makes Actors a pure virtual class
	virtual void doesSomething() = 0;
};

class MapItems : GraphObject {
public:
	virtual void setVisible(bool shouldDisplay);
	virtual double getX() const;
	virtual double getY() const;

};

// I got advice, should start w/ ice
// Should have different parent class
class Ice : public GraphObject {
public:
	// Proper Constructor made for Ice to construct GraphObject
	Ice(int x, int y): GraphObject(IID_ICE, x, y, right, 0.25, 3){
		this->setVisible(true);
	}
	
};

#endif // ACTOR_H_
