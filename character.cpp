//include the necessary header files
#include <iostream>
#include <string>
#include "character.h"

using namespace std;

//Implement constructors
Character::Character(string name, string race, int level, int health)
{
	this->name = name;
	this->race = race;
	this->level = level;
	this->health = health;
}

//Implement getter functions
string Character::getName() const
{
	return name;
}

string Character::getRace() const
{
	return race;
}

int Character::getLevel() const
{
	return level;
}

int Character::getHealth() const
{
	return health;
}

//Implement setter functions
void Character::SetName(string name)
{
	this->name = name;
}

void Character::SetRace(string race)
{
	this->race = race;
}

void Character::SetLevel(int level)
{
	this->level = level;
}

void Character::SetHealth(int health)
{
	this->health = health;
}

//Implement Print function
void Character::Print()
{
	cout << "Character Status: " << endl;
	cout << "Name: " << name << endl;
	cout << "Race: " << race << endl;
	cout << "Level: " << level << endl;
	cout << "Health: " << health << endl;
}




