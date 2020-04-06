#ifndef MAGE_H
#define MAGE_H

#include <iostream>
#include <string>
#include "character.h"
using namespace std;

struct spell {
	string name = "";
	int damage = 0;
	int mana_cost = 0;
};

class Mage : public Character {
private:
	spell spells[10];
	int numOfSpells = 0;
	int mana = 100;
	int active_Spell = 0;

public:
	//Constructors
	Mage(string name = "", string race = "", int level = 0, int health = 0, int mana = 0);

	//Getter functions
	void setMana(int mana);

	//Setter functions
	int getMana() const;

	//Other functions
	int AddSpell(string spell_name, int spell_damage, int mana_cost);
	void nextSpell();
	void Attack(Character * target);
	void Print();
};


#endif