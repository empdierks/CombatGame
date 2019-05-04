// Author: Emily Dierks
// Date: 08/05/17
// Description: Medusa character has armor 3, HP 8, 2d6 attack, and 1d6 defense.
// Her glare attack enacts if attack roll is 12, then opponent turns to stone.
// Except against Harry Potter on his first life (goes to second life) and Vampire Charm
// trumps the Glare attack.

#include "Medusa.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Medusa::Medusa()
{
	HP = 8;
	Armor = 3;
	type = "Medusa";
	unsigned seed;
	seed = time(0);
	srand(seed);
}

int Medusa::attack()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	int dmg = 0;
	int AttResult1 = 0;
	int AttResult2 = 0;

	//attack is 2d6
	AttResult1 = rand() % 6 + 1;
	AttResult2 = rand() % 6 + 1;
	
	dmg = AttResult1 + AttResult2;

	if (dmg == 12)
	{
		return 200;
	}
	else
		return dmg;
	
}

int Medusa::defend(int d)
{
	if (d == 200)
	{
		std::cout << "Medusa used Glare and turned Medusa into stone!" << std::endl;
		setHP(0);
		return 0;
	}
	else
	{
		unsigned seed;
		seed = time(0);
		srand(seed);

		int defense = 0;
		int totalDmg = 0;
		int health = 0;

		//defense is 1d6
		int result1 = rand() % 6 + 1;
		defense = result1;

		std::cout << "Medusa blocks " << defense << " points of damage." << std::endl;
		std::cout << "Medusa's armor soaks up " << Armor << " points of damage." << std::endl;

		//Total damage of attack minus defense and armor
		totalDmg = d - (defense + Armor);

		// decrement HP (health) of defending creature
		// if totalDmg is negative make totalDmg 0 and don't change HP
		// else decrement totalDmg from HP (health)
		if (totalDmg < 0)
		{
			totalDmg = 0;
			return HP;
		}
		else
		{
			health = HP - totalDmg;
			if (health < 0)
			{
				health = 0;
			}
			setHP(health);
			return HP;
		}
	}
	
}