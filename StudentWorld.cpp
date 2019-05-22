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
	//create iceman
	player = new IceMan(this);
	
	//creates both boulder
	createBoulder();
	

	return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move() {
// This code is here merely to allow the game to build, run, and terminate after you hit enter a few times.
// Notice that the return value GWSTATUS_PLAYER_DIED will cause our framework to end the current level.
	
	player->doSomething();
	updateScore();
	bould->doSomething();
	
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
	int health = /* getHealth() */ 0;
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
	srand((unsigned)time(0));
	
	int randomX = (rand()%60);
	while(randomX > 26 && randomX < 34)
	{
		randomX = (rand()%60);
	}
	
	int randomY = (rand()%50) + 6;
	bould = new Boulder(randomX, randomY, this);
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
	bould2 = new Boulder(randomX2, randomY2, this);
	removeBoulderIce(randomX2, randomY2);
}

bool StudentWorld::isBoulderThereL(int x, int y)
{
	//checks for boulders when pressing left
	if(bould2->isVisible() && ((x == bould2->boulderXPos()+4 && y == bould2->boulderYPos()) ||
	   (x == bould2->boulderXPos()+4 && y == bould2->boulderYPos()+1) ||
	   (x == bould2->boulderXPos()+4 && y == bould2->boulderYPos()+2) ||
	   (x == bould2->boulderXPos()+4 && y == bould2->boulderYPos()+3) ||
	   (x == bould2->boulderXPos()+4 && y == bould2->boulderYPos()-1) ||
	   (x == bould2->boulderXPos()+4 && y == bould2->boulderYPos()-2) ||
	   (x == bould2->boulderXPos()+4 && y == bould2->boulderYPos()-3)))
	{
		return true;
	}
	if(bould->isVisible() && ((x == bould->boulderXPos()+4 && y == bould->boulderYPos()) ||
	   (x == bould->boulderXPos()+4 && y == bould->boulderYPos()+1) ||
	   (x == bould->boulderXPos()+4 && y == bould->boulderYPos()+2) ||
	   (x == bould->boulderXPos()+4 && y == bould->boulderYPos()+3) ||
	   (x == bould->boulderXPos()+4 && y == bould->boulderYPos()-1) ||
	   (x == bould->boulderXPos()+4 && y == bould->boulderYPos()-2) ||
	   (x == bould->boulderXPos()+4 && y == bould->boulderYPos()-3)))
	{
		return true;
	}
	return false;
}

bool StudentWorld::isBoulderThereU(int x, int y)
{
	//checks for boulders when pressing up
	if(bould2->isVisible() && ((x == bould2->boulderXPos()+3 && y == bould2->boulderYPos()-4) ||
			(x == bould2->boulderXPos()+2 && y == bould2->boulderYPos()-4) ||
			(x == bould2->boulderXPos()+1 && y == bould2->boulderYPos()-4) ||
			(x == bould2->boulderXPos() && y == bould2->boulderYPos()-4) ||
			(x == bould2->boulderXPos()-1 && y == bould2->boulderYPos()-4) ||
			(x == bould2->boulderXPos()-2 && y == bould2->boulderYPos()-4) ||
			(x == bould2->boulderXPos()-3 && y == bould2->boulderYPos()-4)))
	{
		return true;
	}
	if(bould->isVisible() && ((x == bould->boulderXPos()+3 && y == bould->boulderYPos()-4) ||
			(x == bould->boulderXPos()+2 && y == bould->boulderYPos()-4) ||
			(x == bould->boulderXPos()+1 && y == bould->boulderYPos()-4) ||
			(x == bould->boulderXPos() && y == bould->boulderYPos()-4) ||
			(x == bould->boulderXPos()-1 && y == bould->boulderYPos()-4) ||
			(x == bould->boulderXPos()-2 && y == bould->boulderYPos()-4) ||
			(x == bould->boulderXPos()-3 && y == bould->boulderYPos()-4)))
	{
		return true;
	}
	return false;
}

bool StudentWorld::isBoulderThereR(int x, int y)
{
	//checks for boulders when pressing right
	if(bould2->isVisible() && ((x == bould2->boulderXPos()-4 && y == bould2->boulderYPos()) ||
	   (x == bould2->boulderXPos()-4 && y == bould2->boulderYPos()+1) ||
	   (x == bould2->boulderXPos()-4 && y == bould2->boulderYPos()+2) ||
	   (x == bould2->boulderXPos()-4 && y == bould2->boulderYPos()+3) ||
	   (x == bould2->boulderXPos()-4 && y == bould2->boulderYPos()-1) ||
	   (x == bould2->boulderXPos()-4 && y == bould2->boulderYPos()-2) ||
	   (x == bould2->boulderXPos()-4 && y == bould2->boulderYPos()-3)))
	{
		return true;
	}
	if(bould->isVisible() && ((x == bould->boulderXPos()-4 && y == bould->boulderYPos()) ||
	   (x == bould->boulderXPos()-4 && y == bould->boulderYPos()+1) ||
	   (x == bould->boulderXPos()-4 && y == bould->boulderYPos()+2) ||
	   (x == bould->boulderXPos()-4 && y == bould->boulderYPos()+3) ||
	   (x == bould->boulderXPos()-4 && y == bould->boulderYPos()-1) ||
	   (x == bould->boulderXPos()-4 && y == bould->boulderYPos()-2) ||
	   (x == bould->boulderXPos()-4 && y == bould->boulderYPos()-3)))
	{
		return true;
	}
	return false;
}

bool StudentWorld::isBoulderThereD(int x, int y)
{
	//checks for boulders when pressing down
	if(bould2->isVisible() && ((x == bould2->boulderXPos()+3 && y == bould2->boulderYPos()+4) ||
	   (x == bould2->boulderXPos()+2 && y == bould2->boulderYPos()+4) ||
	   (x == bould2->boulderXPos()+1 && y == bould2->boulderYPos()+4) ||
	   (x == bould2->boulderXPos() && y == bould2->boulderYPos()+4) ||
	   (x == bould2->boulderXPos()-1 && y == bould2->boulderYPos()+4) ||
	   (x == bould2->boulderXPos()-2 && y == bould2->boulderYPos()+4) ||
	   (x == bould2->boulderXPos()-3 && y == bould2->boulderYPos()+4)))
	{
		return true;
	}
	if(bould->isVisible() && ((x == bould->boulderXPos()+3 && y == bould->boulderYPos()+4) ||
	   (x == bould->boulderXPos()+2 && y == bould->boulderYPos()+4) ||
	   (x == bould->boulderXPos()+1 && y == bould->boulderYPos()+4) ||
	   (x == bould->boulderXPos() && y == bould->boulderYPos()+4) ||
	   (x == bould->boulderXPos()-1 && y == bould->boulderYPos()+4) ||
	   (x == bould->boulderXPos()-2 && y == bould->boulderYPos()+4) ||
	   (x == bould->boulderXPos()-3 && y == bould->boulderYPos()+4)))
	{
		return true;
	}
	return false;
}
