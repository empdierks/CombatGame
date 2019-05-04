// Author: Emily Dierks
// Date: 07/29/17
// Description: Vampire character that has armor 1, HP 18, 1d12 attack, and charm defense
// that has 50% chance of preventing an opponent's attack (1d6 defense)

#include "Vampire.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Vampire::Vampire()
{
	HP = 18;
	Armor = 1;
	type = "Dracula the Vampire";
	
}
int Vampire::attack()
{
	unsigned seed;
	seed = time(NULL);
	srand(seed);

	int AttResult = 0;
	
	//attack is 1d12
	AttResult = rand() % 12 + 1;
	return AttResult;

}

bool Vampire::charm()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	//50% chance of working
	int charmResult = rand() % 2 + 1;

	if (charmResult == 1)
		return true;
	else
		return false;
}

int Vampire::defend(int d)
{
	if (d == 200)
	{
		std::cout << "Medusa used Glare on Dracula!" << std::endl;
		if (charm() == true)
		{
			std::cout << "Dracula used Charm and Medusa's Glare did nothing." << std::endl;
			return HP;
		}
		else
		{
			std::cout << "Dracula used Charm but it failed!" << std::endl;
			std::cout << "Dracula turned into Stone!" << std::endl;
			setHP(0);
			return 0;
		}
	}
	else
	{	
		if(charm() == true)
		{
			std::cout << "Dracula used Charm and the opponent's attack did nothing." << std::endl;
			return HP;
		}
		else
		{
			std::cout << "Dracula attempted to use Charm but it failed!" << std::endl;

			unsigned seed;
			seed = time(0);
			srand(seed);

			int result = 0;

			int defense = 0;
			int totalDmg = 0;
			int health = 0;

			//defense is 1d6
			result = rand() % 6 + 1;
			defense = result;

			std::cout << "Dracula blocks " << defense << " points of damage." << std::endl;
			std::cout << "Dracula's armor soaks up " << Armor << " points of damage." << std::endl;

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
}