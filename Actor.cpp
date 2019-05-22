#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

//


// Actor Functions
StudentWorld* Actor::getWorld(){
	return world;
}

// IceMan Functions
void IceMan::doSomething() {
	// If ice man is dead
	if (hitPoints == 0)
		return;
	int ch;
	if(getWorld()->getKey(ch) == true)
	{
		switch(ch)
		{
			case KEY_PRESS_LEFT:
				if(getX()-1 >= 0 && (getWorld()->isBoulderThereL(getX(), getY()) == false)){
					getWorld()->removeBlocks(getX(), getY());
					moveTo(getX()-1, getY());
				}
				setDirection(left);
				break;
			case KEY_PRESS_RIGHT:
				if(getX()+1 <= 60 && (getWorld()->isBoulderThereR(getX(), getY()) == false)){
					getWorld()->removeBlocks(getX()+2, getY());
					moveTo(getX()+1, getY());
				}
				setDirection(right);
				break;
			case KEY_PRESS_DOWN:
				if(getY()-1 >= 0 && (getWorld()->isBoulderThereD(getX(), getY()) == false)){
					getWorld()->removeBlocks(getX()+1, getY()-1);
					moveTo(getX(), getY()-1);
				}
				setDirection(down);
				break;
			case KEY_PRESS_UP:
				if(getY()+1 <= 60 && (getWorld()->isBoulderThereU(getX(), getY()) == false)){
					getWorld()->removeBlocks(getX()+1, getY()+1);
					moveTo(getX(), getY()+1);
				}
				setDirection(up);
				break;
		}
	}
}

//MapObject Functions


// Boulder Functions

// Needs to be finished
void Boulder::doSomething() {
	//immediately returns if boulder is "dead"
	if(!(this->isVisible()))
		return;
	//immediately return if boulder is stable
	if(isStable())
		return;
	if(!isStable())
	{
		this->setVisible(false);
	}
	else if(isWaiting())
	{
		//doSomething or return? idk yet. Needs to be implemented
	}
	else if(isFalling())
	{
		//doSomething and play sound
	}
}
bool Boulder::isFalling() {
	return hasFallen;
}

int Boulder::boulderXPos()
{
	return m_x;
}

int Boulder::boulderYPos()
{
	return m_y;
}

bool Boulder::isStable(){
	//if boulder is at bottom or all the way right return true
	if(m_x > 63 || m_x < 0 || m_y > 63 || m_y <= 0)
		return true;
	if(!(getWorld()->isIceVisable(m_x, m_y-1)))
		return false;
	return true;
}

bool Boulder::isWaiting(){
	return false;
}
