// Author: Emily Dierks
// Date: 08/05/17
// Description: Harry Potter character has armor 0, HP 10, 2d6 attack, and 2d6 defense.
// His special ability is that if his HP drops to 0 he recovers to double HP, but if he
// dies again, he dies.

#include "HarryPotter.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

HarryPotter::HarryPotter()
{
	HP = 10;
	HPtotal = 30;
	Armor = 0;
	type = "Harry Potter";
}

int HarryPotter::attack()
{
	unsigned seed;
	seed = time(0);
	srand(seed);

	//attack is 2d6
	int result1 = rand() % 6 + 1;
	int result2 = rand() % 6 + 1;

	return result1 + result2;

}

void HarryPotter::secondLife()
{
	if (HPtotal == 20)
	{
		std::cout << "The child who lived, lives again!" << std::endl;
		std::cout << "Harry Potter uses Hogwarts and regains 1 life." << std::endl;
		HP = 20;
	}

}

int HarryPotter::defend(int d)
{
	if (d == 200)
	{
		std::cout << "Medusa used Glare on Harry Potter!" << std::endl;
		if (HPtotal > 20)
		{
			secondLife();
			return 20;
		}
		else
		{
			std::cout << "Harry Potter turned into Stone!" << std::endl;
			setHP(0);
			return 0;
		}
	}
	else
	{
		unsigned seed;
		seed = time(0);
		srand(seed);

		int defense = 0;
		int totalDmg = 0;
		int health = 0;

		//defense is 2d6
		int result1 = rand() % 6 + 1;
		int result2 = rand() % 6 + 1;
		defense = result1 + result2;

		std::cout << "Harry Potter blocks " << defense << " points of damage." << std::endl;
		std::cout << "Harry Potter's armor soaks up " << Armor << " points of damage." << std::endl;

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
			if (health < 0)
			{
				health = 0;
			}
			setHP(health);
			setHPtotal(totalDmg);
			return HP;
		}
	}
}

void HarryPotter::setHPtotal(int n)
{
	HPtotal - n;
}