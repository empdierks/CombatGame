// Author: Emily Dierks
// Date: 08/05/17
// Description: Blue Men character has armor 3, HP 12, 2d10 attack, and 3d6 defense.
// Since they a swarm of small individuals, for every 4 points of damage they lose one
// defense die.

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
#include "Creature.hpp"

class BlueMen :public Creature
{
protected:

public:
	BlueMen();
	virtual int attack();
	virtual int defend(int d);
};

#endif // !BLUEMEN_HPP

