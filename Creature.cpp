// Author: Emily Dierks
// Date: 07/29/17
// Description: 

#include "Creature.hpp"

void Creature::setHP(int h)
{
	HP = h;
}

int Creature::getHP()
{
	return HP;
}
void Creature::setArmor(int a)
{
	Armor = a;
}

int Creature::getArmor()
{
	return Armor;
}

std::string Creature::getType()
{
	return type;
}