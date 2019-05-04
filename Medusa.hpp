// Author: Emily Dierks
// Date: 08/05/17
// Description: Medusa character has armor 3, HP 8, 2d6 attack, and 1d6 defense.
// Her glare attack enacts if attack roll is 12, then opponent turns to stone.
// Except against Harry Potter on his first life (goes to second life) and Vampire Charm
// trumps the Glare attack.

#ifndef MEDUSA_HPP
#define MEDUSA_HPP
#include "Creature.hpp"

class Medusa : public Creature
{
protected:
public:
	Medusa();
	virtual int attack();
	virtual int defend(int d);

}; 
#endif

