#include <iostream>
#include <string>

using namespace std;

#include "barbarian.h"

//Implement constructors
Barbarian::Barbarian(string name, string race, int level, int health, int stamina)
	: Character(name, race, level, health), stamina(stamina)
{

}

//Implement getter functions
void Barbarian::SetStamina(int stamina)
{
	this->stamina = stamina;
}

//Implement setter functions
int Barbarian::getStamina() const
{
	return stamina;
}

/*
 *A public function "EquipWeapon()" that takes
 *a string name, int damage, and int staminacost to create a new weapon
 *and assign it to the barbarian's "activeweapon".
 */
void Barbarian::EquipWeapon(string name, int damage, int stamina_cost)
{
	active_weapon.name = name;
	active_weapon.damage = damage;
	active_weapon.stamina_cost = stamina_cost;
}

/*
 *A public function that overloads "Attack()" taking a pointer to a character
 *and reduce that character's health based on the active_weapon's damage.
 *The function then prints:
 *<CHARACTER NAME> attacked <TARGET NAME> with a <WEAPON NAME>, dealing <WEAPON DAMAGE> damage.
 *
 *However, if the Barbarian does not have a weapon, prints out:
 *Barbarian has no weapon!
 *
 *If the Barbarian have less stamina than the weapon's stamina_cost, prints out:
 *Insufficient stamina points!
 */
void Barbarian::Attack(Character *target)
{   
    if (active_weapon.name == "")
    {
        cout << "Barbarian has no weapon!" << endl;
    }
    else
    {
        if (stamina < active_weapon.stamina_cost)
        {
            cout << "Insufficient stamina points!" << endl;
        }
        else 
        {
            target->setHealth(target->getHealth() - active_weapon.damage);
            cout << getName() << " attacked " << target->getName() 
                 << " with a " << active_weapon.name << ", dealing " 
                 << active_weapon.damage << " damage." << endl;
        }
    }
}

/*
 *A public function that overloads"Print()" that prints out the variables in this format:
 *Character Status :
 *Name: Bob
 *Race: Human
 *Occupation: Barbarian
 *Level: 10
 *Health: 100
 *Weapon: Sword
 */
void Barbarian::Print()
{
    cout << "Character Status: " << endl;
    cout << "Name: " << getName() << endl;
    cout << "Race: " << getRace() << endl;
    cout << "Occupation: Barbarian" << endl;
    cout << "Level: " << getLevel() << endl;
    cout << "Health: " << getHealth() << endl;
    cout << "Weapon: " << active_weapon.name << endl;
    cout << endl;
}




