// Author: Emily Dierks
// Date: 07/29/17
// Description: Barbarian character has armor 0, HP 12, 2d6 attack, and 2d6 defense

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
#include "Creature.hpp"

class Barbarian : public Creature {
protected:

public:
	Barbarian();
	virtual int attack();
	virtual int defend(int d);

};
#endif // !BARBARIAN_HPP

