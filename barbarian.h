#ifndef BARBARIAN_H
#define BARBARIAN_H

#include <iostream>
#include <string>
#include "character.h"
using namespace std;

struct weapon {
	string name = "";
	int damage = 0;
	int stamina_cost = 0;
};

class Barbarian : public Character {
private:
	weapon active_weapon;
	int stamina = 100;

public:
	//Constructors
	Barbarian(string name = "", string race = "", int level = 0, int health = 0, int stamina = 0);

	//Getters functions
	void SetStamina(int stamina);

	//Setters functions
	int getStamina() const;

	//Other functions
	void EquipWeapon(string name, int damage, int stamina_cost);
	void Attack(Character * target);
	void Print();
};

#endif