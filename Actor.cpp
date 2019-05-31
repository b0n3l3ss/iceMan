#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp



// Actor Functions
StudentWorld* Actor::getWorld(){
	return world;
}

bool Actor::isDead() const {
	return isItDead;
}

void Actor::setDead() {
	isItDead = true;
}

// IceMan Functions

void IceMan::doSomething() {
	getWorld()->isMapObjectThere(getX(), getY());
	if (hitPoints == 0)
		return;
	int ch;
	if(getWorld()->getKey(ch) == true)
	{
		switch(ch)
		{
			case KEY_PRESS_LEFT:
				if(getX()-1 >= 0 && (getWorld()->isBoulderThereL(getX(), getY()) == false) && (getDirection() == left)){
					getWorld()->removeBlocks(getX(), getY());
					moveTo(getX()-1, getY());
					getWorld()->isMapObjectThere(getX(), getY());
				}
				setDirection(left);
				break;
			case KEY_PRESS_RIGHT:
				if(getX()+1 <= 60 && (getWorld()->isBoulderThereR(getX(), getY()) == false) && (getDirection() == right)){
					getWorld()->removeBlocks(getX()+2, getY());
					moveTo(getX()+1, getY());
					getWorld()->isMapObjectThere(getX(), getY());
				}
				setDirection(right);
				break;
			case KEY_PRESS_DOWN:
				if(getY()-1 >= 0 && (getWorld()->isBoulderThereD(getX(), getY()) == false) && (getDirection() == down)){
					getWorld()->removeBlocks(getX()+1, getY()-1);
					moveTo(getX(), getY()-1);
					getWorld()->isMapObjectThere(getX(), getY());
				}
				setDirection(down);
				break;
			case KEY_PRESS_UP:
				if(getY()+1 <= 60 && (getWorld()->isBoulderThereU(getX(), getY()) == false) && (getDirection() == up)){
					getWorld()->removeBlocks(getX()+1, getY()+1);
					moveTo(getX(), getY()+1);
					getWorld()->isMapObjectThere(getX(), getY());
				}
				setDirection(up);
				break;
			case KEY_PRESS_SPACE:
				if (numSquirts > 0) {
					if (getDirection() == right)
					{
						if (getWorld()->checkInitialSquirt(getX()+4, getY())) {
							getWorld()->playSound(SOUND_PLAYER_SQUIRT);
							--numSquirts;
						}
						else
							getWorld()->createSquirt(getX() + 4, getY(), right);
					}
					else if (getDirection() == up)
					{
						if (getWorld()->checkInitialSquirt(getX(), getY()+4)) {
							getWorld()->playSound(SOUND_PLAYER_SQUIRT);
							--numSquirts;
						}
						else
							getWorld()->createSquirt(getX(), getY() + 4, up);
					}
					else if (getDirection() == left)
					{
						if (getWorld()->checkInitialSquirt(getX()-4, getY())) {
							getWorld()->playSound(SOUND_PLAYER_SQUIRT);
							--numSquirts;
						}
						else
							getWorld()->createSquirt(getX() - 4, getY(), left);
					}
					else
					{
						if (getWorld()->checkInitialSquirt(getX(), getY()-4)) {
							getWorld()->playSound(SOUND_PLAYER_SQUIRT);
							--numSquirts;
						}
						else
							getWorld()->createSquirt(getX(), getY() - 4, down);
					}
				}
				break;
			case KEY_PRESS_TAB:
				if(numGold > 0) {
					getWorld()->dropGold(getX(), getY());
					break;
				}
				break;
			case KEY_PRESS_ESCAPE:
				makeHimDead();
				break;
		}
	}
}

void IceMan::incGold() {
	++numGold;
}
void IceMan::decGold() {
	--numGold;
}
void IceMan::incOil() {
	++numOil;
}
void IceMan::incSquirt() {
	++numSquirts;
}
void IceMan::decSquirt() {
	--numSquirts;
}

int IceMan::getGold() const {
	return numGold;
}
int IceMan::getHitPoints() const 
{
	return hitPoints;
}
int IceMan::getBarrels() const {
	return numOil;
}
int IceMan::getSquirts() const {
	return numSquirts;

}
int IceMan::getSonar() const {
	return numSonar;
}

void IceMan::makeHimDead(){
	getWorld()->playSound(SOUND_PLAYER_GIVE_UP);
	hitPoints = 0;
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
		if(hasFallen == false){
			getWorld()->playSound(SOUND_FALLING_ROCK);
			hasFallen = true;
		}
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
	if(!(getWorld()->isIceVisable(getX(), getY()-1, down)))
		return false;
	return true;
}

bool Boulder::doneWaiting(){
	if(m_waitingTime >= 30)
		return true;
	m_waitingTime++;
	return false;
}


// Gold Functions
void Gold::doSomething(){
	if(isBribe == true)
	{
		if(bribeTime >= 100)
		{
			this->setDead();
			isBribe = false;
		}
		bribeTime++;
	}
}

void Gold::updateisBribeState(bool update) {
	isBribe = update;
}
bool Gold::isBribeState() const {
	return isBribe;
}



// Oil Barrel Functions

//Squirt Functions

void Squirt::doSomething(){
	if(isSquirt && squirtTime <= 6)
	{
		//checks to see if the squirt is about to hit an actor object
		getWorld()->checkSquirtRadius(getX(), getY(), vecPosition);
		if(getDirection() == right)
		{
			if(squirtTime == 0)
				getWorld()->playSound(SOUND_PLAYER_SQUIRT);
			moveTo(getX()+1, getY());
			squirtTime++;
			if(getWorld()->isIceVisable(getX()+3, getY(), right))
				setDead();
		}
		if(getDirection() == left)
		{
			if(squirtTime == 0)
				getWorld()->playSound(SOUND_PLAYER_SQUIRT);
			moveTo(getX()-1, getY());
			squirtTime++;
			if(getWorld()->isIceVisable(getX(), getY(), left))
				setDead();
		}
		if(getDirection() == up)
		{
			if(squirtTime == 0)
				getWorld()->playSound(SOUND_PLAYER_SQUIRT);
			moveTo(getX(), getY()+1);
			squirtTime++;
			if(getWorld()->isIceVisable(getX(), getY()+3, up))
				setDead();
		}
		if(getDirection() == down)
		{
			if(squirtTime == 0)
				getWorld()->playSound(SOUND_PLAYER_SQUIRT);
			moveTo(getX(), getY()-1);
			squirtTime++;
			if(getWorld()->isIceVisable(getX(), getY(), down))
				setDead();
		}
	}
	if(squirtTime > 6)
		setDead();
}

bool Squirt::getIsSquirt() const{
	return isSquirt;
}

void Squirt::updateIsSquirt(bool update){
	isSquirt = update;
}

int Squirt::getVecPosition() const {
	return vecPosition;
}
