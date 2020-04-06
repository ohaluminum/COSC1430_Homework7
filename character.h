#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
using namespace std;

class Character {
private:
	string name;
	string race;
	int level;
	int health;

public:
	//constructors
	Character(string name = "", string race = "", int level = 0, int health = 0);

	//getter functions
	string getName() const;
	string getRace() const;
	int getLevel() const;
	int getHealth() const;

	//setter functions
	void SetName(string name);
	void SetRace(string race);
	void SetLevel(int level);
	void SetHealth(int health);
	
	//other functions
	void Print();
	virtual void Attack(Character *target) = 0;
};

#endif