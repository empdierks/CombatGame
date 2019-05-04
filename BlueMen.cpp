// Author: Emily Dierks
// Date: 08/05/17
// Description: Blue Men character has armor 3, HP 12, 2d10 attack, and 3d6 defense.
// Since they a swarm of small individuals, for every 4 points of damage they lose one
// defense die.

#include "BlueMen.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

BlueMen::BlueMen()
{
	HP = 12;
	Armor = 3;
	type = "The Blue Men";
}

int BlueMen::attack()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	//attack is 2d10
	int result1 = rand() % 10 + 1;
	int result2 = rand() % 10 + 1;
	return result1 + result2;
}

// Defend's Blue Men from attacker's damage (damage dealt is parameter) and
// returns health after attack and defense
int BlueMen::defend(int d)
{
	if (d == 200)
	{
		std::cout << "Medusa used Glare and turned the Blue Men into stone!" << std::endl;
		setHP(0);
		return 0;
	}
	else
	{
		unsigned seed;
		seed = time(0);
		srand(seed);
		
		int result1 = 0;
		int result2 = 0;
		int result3 = 0;

		int defense = 0;
		int totalDmg = 0;
		int health = 0;

		//for every 4 points of damage they lose 1 defense die
		if (HP <= 12 && HP > 8)
		{	//defense is 3d6
			result1 = rand() % 6 + 1;
			result2 = rand() % 6 + 1;
			result3 = rand() % 6 + 1;
			defense = result1 + result2 + result3;
		}
		else if (HP <= 8 && HP > 4)
		{	//defense is 2d6
			result1 = rand() % 6 + 1;
			result2 = rand() % 6 + 1;
			defense = result1 + result2;
		}
		else if (HP <= 4 && HP > 0)
		{	//defense is 1d6
			result1 = rand() % 6 + 1;
			defense = result1;
		}
	std::cout << "The Blue Men block " << defense << " points of damage." << std::endl;
	std::cout << "The Blue Men's armor soaks up " << Armor << " points of damage." << std::endl;

	//Total damage of attack minus defense and armor
	totalDmg = d - (defense + Armor);

	//decrement HP (health) of defending creature
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
		setHP(health);
		return HP;
	}
	}
}