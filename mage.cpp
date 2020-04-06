#include <iostream>
#include <string>

using namespace std;

#include "mage.h"

//Implement constructors
Mage::Mage(string name, string race, int level, int health, int mana)
	: Character(name, race, level, health), mana(mana)
{

}

//Implement getter functions
void Mage::setMana(int mana)
{
	this->mana = mana;
}

//Implement setter functions
int Mage::getMana() const
{
	return mana;
}

/*
 *A public function called "AddSpell()" that takes the spell_name, spell_damage, and int mana_cost
 *to add a new spell 
 *and return the new number of spells.
 *However, if the wizard already has 10 spells, prints out:
 *"Spell limits reached!"
 */
int Mage::AddSpell(string spell_name, int spell_damage, int mana_cost)
{
	if (numOfSpells == 10)
	{
		cout << "Spell limits reached!" << endl;
	}
	else
	{
		spells[numOfSpells].name = spell_name;
		spells[numOfSpells].damage = spell_damage;
		spells[numOfSpells].mana_cost = mana_cost;

		numOfSpells++;
	}
	return numOfSpells;
}

/*A public function called "nextSpell() that increases the value activeSpell
 *so that it moves to the next spell in the "spells" array. 
 *Once the value of activeSpell is the same as numOfSpells, then reset the value of active_Spell to 0.
 */
void Mage::nextSpell()
{
	if (active_Spell = numOfSpells)
	{
		active_Spell = 0;
	}
	else
	{
		active_Spell++;
	}
}

/*A public function that overloads "Attack()" that takes a pointer to a character 
 *and reduce that character's health based on the active_Spell's damage.
 *Once a spell has been casted, the "nextSpell()" must be called to go to the next spell.
 *If the Mage does not have any spells, prints out:
 *This mage has no spells!

 *If the Mage have less mana than the spell's mana_cost, prints out:
 *Insufficient mana points!
 */
void Mage::Attack(Character *target)
{
	if (numOfSpells == 0)
	{
		cout << "This mage has no spells!" << endl;
	}
	else
	{
		if (mana < spells[active_Spell].mana_cost)
		{
			cout << "Insufficient mana points!" << endl;
		}
		else
		{
			target->setHealth(target->getHealth() - spells[active_Spell].damage);
			nextSpell();
		}
	}

}

/*A public function that overloads"Print()" that prints out the variables in this format:
 *Character Status:
 *Name: Bobbi
 *Race: Human
 *Occupation: Mage
 *Level: 10
 *Health: 100
 *Spells:
 *Fireball
 *Waterball
 *Earthball
 */
void Mage::Print()
{
	cout << "Character Status: " << endl;
	cout << "Name: " << getName() << endl;
	cout << "Race: " << getRace() << endl;
	cout << "Occupation: Mage" << endl;
	cout << "Level: " << getLevel() << endl;
	cout << "Health: " << getHealth() << endl;
	cout << "Spells: " << endl;

	for (int i = 0; i < numOfSpells; i++)
	{
		cout << spells[i].name << endl;
	}

	cout << endl;
}




	

	
	


