// Author: Emily Dierks
// Date: 08/05/17
// Description: Harry Potter character has armor 0, HP 10, 2d6 attack, and 2d6 defense.
// His special ability is that if his HP drops to 0 he recovers to double HP, but if he
// dies again, he dies.

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP
#include "Creature.hpp"

class HarryPotter : public Creature
{
protected:
	int HPtotal;

public:
	HarryPotter();
	virtual int attack();
	virtual int defend(int d);
	void secondLife();
	void setHPtotal(int n);
};
#endif