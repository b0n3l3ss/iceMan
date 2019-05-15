#include "Actor.h"
#include "StudentWorld.h"

// Students:  Add code to this file (if you wish), Actor.h, StudentWorld.h, and StudentWorld.cpp

//

StudentWorld* IceMan::getWorld(){
	return world;
}

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
				moveTo(getX()-1, getY());
				setDirection(left);
				break;
			case KEY_PRESS_RIGHT:
				moveTo(getX()+1, getY());
				setDirection(right);
				break;
			case KEY_PRESS_DOWN:
				moveTo(getX(), getY()-1);
				setDirection(down);
				break;
			case KEY_PRESS_UP:
				moveTo(getX(), getY()+1);
				setDirection(up);
				break;
		}
	}
	// Needs a lot more code lolololol
}
