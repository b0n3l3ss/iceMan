#include "StudentWorld.h"
#include <cstdlib>
#include <ctime>

using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp

int StudentWorld::init() {
	// Create & print out ice with 2d array
	createIce();
	
	//create iceman
	player = new IceMan(this);
	
	//creates both boulder
	createBoulder();
	

	return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move() {
// This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
// Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
	
	if(player->getHitPoints() <= 0)
		return GWSTATUS_PLAYER_DIED;
	player->doSomething();
	updateScore();
	//bould->doSomething();
	//gameActors[i]->doSomething();
	//bould2->doSomething();
	for (int i = 0; i < bouldNum; ++i) {
		gameActors[i]->doSomething();
	}
	
	return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp() {
	for(int i = 0; i < 64; ++i)
	{
		for(int j = 0; j < 64; ++j)
		{
			if(ice[i][j] != nullptr){
				delete ice[i][j];
				ice[i][j] = nullptr;
			}
		}
	}
	if(player != nullptr){
		delete player;
		player = nullptr;
	}
}

void StudentWorld::createIce(){
	for (int i = 0; i < 64; ++i) {
		for (int j = 0; j < 64; ++j){
			ice[i][j] = new Ice(i, j);
			
			if(j >= 60)	//sets top row to clear
				ice[i][j]->setVisible(false);
			
			// This makes the initial cavern
			if (i < 34 && i >= 30 && j > 4)
				ice[i][j]->setVisible(false);
		}
	}
}

void StudentWorld::removeBlocks(int x, int y)
{
	//if the iceman destroys atleast one block then the dig sound gets played
	if(ice[x][y-64]->isVisible())
	{
		playSound(SOUND_DIG);
	}
	
	else if (ice[x][y - 63]->isVisible()) {
		playSound(SOUND_DIG);
	}
	
	else if (ice[x][y - 62]->isVisible()) {
		playSound(SOUND_DIG);
	}

	else if (ice[x][y - 61]->isVisible()) {
		playSound(SOUND_DIG);
	}

	else if (ice[x + 1][y - 64]->isVisible()) {
		playSound(SOUND_DIG);
	}

	else if (ice[x + 1][y - 63]->isVisible()) {
		playSound(SOUND_DIG);
	}
	
	else if (ice[x + 1][y - 62]->isVisible()) {
		playSound(SOUND_DIG);
	}

	else if (ice[x + 1][y - 61]->isVisible()) {
		playSound(SOUND_DIG);
	}

	else if (ice[x + 2][y - 64]->isVisible()) {
		playSound(SOUND_DIG);
	}

	else if (ice[x + 2][y - 63]->isVisible()) {
		playSound(SOUND_DIG);
	}

	else if (ice[x + 2][y - 62]->isVisible()) {
		playSound(SOUND_DIG);
	}

	else if (ice[x + 2][y - 61]->isVisible()) {
		playSound(SOUND_DIG);
	}

	else if (ice[x + 3][y - 64]->isVisible()) {
		playSound(SOUND_DIG);
	}


	else if (ice[x + 3][y - 63]->isVisible()) {
		playSound(SOUND_DIG);
	}

	else if (ice[x + 3][y - 62]->isVisible()) {
		playSound(SOUND_DIG);
	}

	else if(ice[x+3][y-61]->isVisible())
	{
		playSound(SOUND_DIG);
	}
	//sets all blocks the iceman touches to not visable
	ice[x][y-64]->setVisible(false);
	ice[x][y-63]->setVisible(false);
	ice[x][y-62]->setVisible(false);
	ice[x][y-61]->setVisible(false);
	
	ice[x+1][y-64]->setVisible(false);
	ice[x+1][y-63]->setVisible(false);
	ice[x+1][y-62]->setVisible(false);
	ice[x+1][y-61]->setVisible(false);
	
	ice[x+2][y-64]->setVisible(false);
	ice[x+2][y-63]->setVisible(false);
	ice[x+2][y-62]->setVisible(false);
	ice[x+2][y-61]->setVisible(false);
	
	ice[x+3][y-64]->setVisible(false);
	ice[x+3][y-63]->setVisible(false);
	ice[x+3][y-62]->setVisible(false);
	ice[x+3][y-61]->setVisible(false);
	
}

StudentWorld::~StudentWorld(){
	for(int i = 0; i < 64; ++i)
	{
		for(int j = 0; j < 64; ++j)
		{
			if(ice[i][j] != nullptr)
				delete ice[i][j];
		}
	}
	if(player != nullptr)
		delete player;
}

//puts all values nicely into a string for the scoreboard
string StudentWorld::formatScoreBoard(int level, int lives, int health,
	int squirts, int gold, int barrels, int sonar, int score){
	string str = "Level: " + to_string(level) + " Lives: " + to_string(lives) 
		+  " Health: " + to_string(health) + "% Water: " + to_string(squirts) 
		+ " Gold: " + to_string(gold) + " Oil Left: " + to_string(barrels) 
		+ " Sonar: " + to_string(sonar) + " Score: ";
	
	//checks to see what the score is an determines how many zeroes to put in front
	//Honestly Jonas there is probably a better way of doing this using setprecision 
	//but this seemed easier to do. If you want to change it feel free to
	if((score / 10) <= 0)
		str += "00000" + to_string(score);
	else if((score / 100) <= 0)
		str += "0000" + to_string(score);
	else if((score / 1000) <= 0)
		str += "000" + to_string(score);
	else if((score / 10000) <= 0)
		str +=  "00" + to_string(score);
	else if((score / 100000) <= 0)
		str +=  "0" + to_string(score);
	else
		str += to_string(score);
	return str;
}

void StudentWorld::updateScore(){
	int level = getLevel();
	int lives = getLives();
	
	//Needs to be implented properly
	//Is currently only holding dummy variables
	int health = player->getHitPoints()*10;
	int squirts = /*getSquirts() */ 0;
	int gold = /* getGold() */ 0;
	int barrels = /* getBarrels() */ 0;
	int sonar = /* getSonar() */ 0;
	
	int score = getScore();
	string s = formatScoreBoard(level, lives, health, squirts, gold, barrels, sonar, score);
	setGameStatText(s);
}

void StudentWorld::removeBoulderIce(int x, int y)
{
	ice[x][y]->setVisible(false);
	ice[x+1][y]->setVisible(false);
	ice[x+2][y]->setVisible(false);
	ice[x+3][y]->setVisible(false);
	
	ice[x][y+1]->setVisible(false);
	ice[x+1][y+1]->setVisible(false);
	ice[x+2][y+1]->setVisible(false);
	ice[x+3][y+1]->setVisible(false);
	
	ice[x][y+2]->setVisible(false);
	ice[x+1][y+2]->setVisible(false);
	ice[x+2][y+2]->setVisible(false);
	ice[x+3][y+2]->setVisible(false);
	
	ice[x][y+3]->setVisible(false);
	ice[x+1][y+3]->setVisible(false);
	ice[x+2][y+3]->setVisible(false);
	ice[x+3][y+3]->setVisible(false);
}

//creates both boulders
void StudentWorld::createBoulder() {
	

	// For Some reason, this loop is not working. I tried to insert
	// the boulders through a temp, but it did not work too well.  
	// Iceman could walk through one of the boulders and would not fall
	// down if there was no ice under it.  Also, take a look at the header file.
	// I added a variable that contains the number of boulders per level, but 
	// I dont think that this is going to work the way I wrote it. It needs to
	// be updated each time the level starts, instead of when the sttudent world
	// is made. So we might need to create a method that updates the number of 
	// boulders to be called in the init() function in StudentWorld

	srand((unsigned)time(0));
	for (int i = 0; i < bouldNum; ++i) {
		
		int randomX = (rand() % 60);
		while((gameActors.size() == 0) && (randomX > 26 && randomX < 34))
		{
			randomX = (rand()%60);
		}
		
		int randomY = (rand() % 50) + 6;
		
		checkForObject(randomX, randomY);
		
		Boulder* temp = new Boulder(randomX, randomY, this);
		gameActors.push_back(temp);
		removeBoulderIce(randomX, randomY);
	}
	/*srand((unsigned)time(0));
	
	int randomX = (rand()%60);
	while(randomX > 26 && randomX < 34)
	{
		randomX = (rand()%60);
	}
	
	int randomY = (rand()%50) + 6;
	Boulder* bould = nullptr;
	bould = new Boulder(randomX, randomY, this);
	// Pushing the pointer into a vector
	gameActors.push_back(bould);
	removeBoulderIce(randomX, randomY);
	
	int randomX2 = (rand()%60);
	while((randomX2 > 26 && randomX2 < 34) || ((randomX2 >= randomX) && (randomX2 < randomX+3)))
	{
		randomX2 = (rand()%60);
	}
	int randomY2 = (rand()%50) + 6;
	while((randomY2 >= randomY) && (randomY2 < randomY+3))
	{
		randomY2 = (rand()%50) + 6;
	}
	Boulder* bould2 = nullptr;
	bould2 = new Boulder(randomX2, randomY2, this);
	// Pushing second boulder into the vector
	gameActors.push_back(bould2);
	removeBoulderIce(randomX2, randomY2); */
}

bool StudentWorld::isBoulderThereL(int x, int y)
{
	//checks for boulders when pressing left
	for (int i = 0; i < gameActors.size(); ++i) {
		if(gameActors[i]->isVisible() &&
			((x == gameActors[i]->getX()+4 && y == gameActors[i]->getY()) ||
			(x == gameActors[i]->getX()+4 && y == gameActors[i]->getY()+1) ||
			(x == gameActors[i]->getX()+4 && y == gameActors[i]->getY()+2) ||
			(x == gameActors[i]->getX()+4 && y == gameActors[i]->getY()+3) ||
			(x == gameActors[i]->getX()+4 && y == gameActors[i]->getY()-1) ||
			(x == gameActors[i]->getX()+4 && y == gameActors[i]->getY()-2) ||
			(x == gameActors[i]->getX()+4 && y == gameActors[i]->getY()-3))) {
			
			return true;
		}
	}
	
	return false;
}

bool StudentWorld::isBoulderThereU(int x, int y)
{
	//checks for boulders when pressing up
	for(int i = 0; i < gameActors.size(); ++i) {
		if(gameActors[i]->isVisible() && ((x == gameActors[i]->getX()+3 && y == gameActors[i]->getY()-4) ||
			(x == gameActors[i]->getX()+2 && y == gameActors[i]->getY()-4) ||
			(x == gameActors[i]->getX()+1 && y == gameActors[i]->getY()-4) ||
			(x == gameActors[i]->getX() && y == gameActors[i]->getY()-4) ||
			(x == gameActors[i]->getX()-1 && y == gameActors[i]->getY()-4) ||
			(x == gameActors[i]->getX()-2 && y == gameActors[i]->getY()-4) ||
			(x == gameActors[i]->getX()-3 && y == gameActors[i]->getY()-4))) {
			return true;
		}
	}
	
	return false;
}

bool StudentWorld::isBoulderThereR(int x, int y)
{
	//checks for boulders when pressing right
	for (int i = 0; i < gameActors.size(); ++i) {
		if(gameActors[i]->isVisible() && ((x == gameActors[i]->getX()-4 && y == gameActors[i]->getY()) ||
			(x == gameActors[i]->getX()-4 && y == gameActors[i]->getY()+1) ||
			(x == gameActors[i]->getX()-4 && y == gameActors[i]->getY()+2) ||
			(x == gameActors[i]->getX()-4 && y == gameActors[i]->getY()+3) ||
			(x == gameActors[i]->getX()-4 && y == gameActors[i]->getY()-1) ||
			(x == gameActors[i]->getX()-4 && y == gameActors[i]->getY()-2) ||
			(x == gameActors[i]->getX()-4 && y == gameActors[i]->getY()-3))) {
			return true;
		}
	}
	
	return false;
}

bool StudentWorld::isBoulderThereD(int x, int y)
{
	//checks for boulders when pressing down
	for (int i = 0; i < gameActors.size(); ++i) {
		if(gameActors[i]->isVisible() && ((x == gameActors[i]->getX()+3 && y == gameActors[i]->getY()+4) ||
			(x == gameActors[i]->getX()+2 && y == gameActors[i]->getY()+4) ||
			(x == gameActors[i]->getX()+1 && y == gameActors[i]->getY()+4) ||
			(x == gameActors[i]->getX() && y == gameActors[i]->getY()+4) ||
			(x == gameActors[i]->getX()-1 && y == gameActors[i]->getY()+4) ||
			(x == gameActors[i]->getX()-2 && y == gameActors[i]->getY()+4) ||
			(x == gameActors[i]->getX()-3 && y == gameActors[i]->getY()+4))) {
			return true;
		}
	}
	
	return false;
}

void StudentWorld::checkForObject(int &x, int &y){
	
	for(int i = 0; i < gameActors.size(); i++)
	{
		if(gameActors[i] == nullptr)
		{
			//do Nothing! Yay!
		}
		else if( (x > 26 && x < 34) || ( ( 
			( (x >= gameActors[i]->getX() ) && (x <= gameActors[i]->getX()+4 ) )
			&& ((y >= gameActors[i]->getY()) && (y <= gameActors[i]->getY()+4) ) ) ) )
		{
			x = rand() % 60;
			y = (rand()%50) + 6;
			i = -1;
		}
	}
}

bool StudentWorld::isIceVisable(int x, int y)
{
	for(int i = 0; i <= 3; i++)
	{
		//if ice does not exist just return true to avoid bad access error
		if(ice[x+i][y] == nullptr)
			return true;
		if(ice[x+i][y]->isVisible())
			return true;
	}
	return false;
}
