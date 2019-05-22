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

int IceMan::getHitPoints()
{
	return hitPoints;
}

//MapObject Functions


// Boulder Functions


void Boulder::doSomething() {
	//immediately returns if boulder is "dead"
	if(!(this->isVisible()))
		return;
	//immediately return if boulder is stable
	else if(isStable())
		return;
	//if rock is waiting return
	else if(!(doneWaiting()))
		return;
	else if(isFalling())
	{
		//doSomething and play sound
		moveTo(getX(), getY()-1);
		getWorld()->playSound(SOUND_FALLING_ROCK);
		isFalling();
	}
}
bool Boulder::isFalling() {
	if(isStable())
	{
		this->setVisible(false);
		return false;
	}
	return true;
}



bool Boulder::isStable(){
	//if boulder is at bottom
	if(getY() <= 0)
		return true;
	if(getWorld()->isBoulderThereD(getX(), getY()))
		return true;
	if(!(getWorld()->isIceVisable(getX(), getY()-1)))
		return false;
	return true;
}

bool Boulder::doneWaiting(){
	if(m_waitingTime >= 30)
		return true;
	m_waitingTime++;
	return false;
}
