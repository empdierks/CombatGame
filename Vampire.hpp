// Author: Emily Dierks
// Date: 07/29/17
// Description: Vampire character that has armor 1, HP 18, 1d12 attack, and charm defense
// that has 50% chance of preventing an opponent's attack (1d6 defense)

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP
#include "Creature.hpp"

class Vampire : public Creature {

protected:

public:
	Vampire();
	virtual int attack();
	virtual int defend(int d);
	bool charm();

};
#endif