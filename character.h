#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
using namespace std;

class Character 
{
private:
	string name;
	string race;
	int level;
	int health;

public:
	//Constructors
	Character(string name = "", string race = "", int level = 0, int health = 0);

	//Getter functions
	string getName() const;
	string getRace() const;
	int getLevel() const;
	int getHealth() const;

	//Setter functions
	void setName(string name);
	void setRace(string race);
	void setLevel(int level);
	void setHealth(int health);
	
	//Other functions
	void Print();
	virtual void Attack(Character *target) = 0;
};

#endif