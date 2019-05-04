// Author: Emily Dierks
// Date: 07/29/17
// Description: This program creates the menu and game play implementation for the Fantasy Combat Game.
// User will select two fighters, attack and defend, decrement health (HP), and continue until one
// fighter's health (HP) hits 0.

#include "Play_Game.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;


Play_Game::Play_Game()
{
	round = 1;
}



void Play_Game::game()
{
	//player creation
	cout << "Player 1" << endl;
	player1 = playerSelection();
	cout << "Player 2" << endl;
	player2 = playerSelection();

	//randomly select first player & assign attacker and defender
	// for first round
	unsigned seed;
	seed = time(0);
	srand(seed);

	Creature **attacker = NULL;
	Creature **defender = NULL;

	int result = rand() % 2 + 1;

	if (result == 1)
	{
		attacker = &player1;
		defender = &player2;
	}
	else
	{
		attacker = &player2;
		defender = &player1;
	}

	int defHP = 1;
	//loop fight and defense of players
	do{
		int dmg = 0;
		cout << "Round " << round << ", Fight!" << endl;

		//first player attacks
		dmg = (**attacker).attack();
		std::cout << (**attacker).getType() << " did " << dmg <<" points of damage." << std::endl;

		// second player defends and returns final health after
		// calculating defense and special abilities
		defHP = (**defender).defend(dmg);

		cout << endl;
		//display round results
		cout << "Round " << round << " Results" << endl;
		cout << "Player 1 (" << player1->getType()<< ") HP: " << player1->getHP() << endl;
		cout << "Player 2 (" << player2->getType()<< ") HP: " << player2->getHP() << endl;
		cout << endl;
		round++;

		//switch attacker and defender
		if (attacker == &player1)
		{
			attacker = NULL;
			defender = NULL;
			attacker = &player2;
			defender = &player1;
		}
		else
		{
			attacker = NULL;
			defender = NULL;
			attacker = &player1;
			defender = &player2;
		}
	} while (defHP > 0);
	
	//display winning fighter
	if (player1->getHP() <= 0)
		cout << "Player 2 (" << player2->getType() << ") is Victorious!" << endl;
	else if (player2->getHP() <= 0)
		cout << "Player 1 (" << player1->getType() << ") is Victorious!" << endl;

	attacker = NULL;
	defender = NULL;
	delete player1;
	delete player2;
}


Creature* Play_Game::playerSelection()
{
	int choice;
	Creature *player;

	cout << "Choose your character: "<< endl;;
	cout << "1. Dracula the Vampire" << endl;
	cout << "2. Conan the Barbarian" << endl;
	cout << "3. The Blue Men" << endl;
	cout << "4. Medusa " << endl;
	cout << "5. Harry Potter" << endl;

	cin >> choice;
	while ((choice !=1 ) && (choice !=2 ) && (choice !=3 ) && (choice !=4 ) && (choice != 5))
	{
		cout << "Invalid entry. Please enter either 1, 2, 3, 4, or 5:";
		cin >> choice;
		cin.clear();
		cin.ignore(1000, '\n');
	}
	switch (choice)
	{
	case 1:
	{	player = new Vampire();
		cout << "You chose Dracula the Vampire"<< endl;
		return player;
		break;
	}
	case 2:
	{
		player = new Barbarian();
		cout << "You chose Conan the Barbarian." << endl;
		return player;
		break;
	}
	case 3:
	{
		player = new BlueMen();
		cout << "You chose the Blue Men." << endl;
		return player;
		break;
	}
	case 4:
	{
		player = new Medusa();
		cout << "You chose Medusa." << endl;
		return player;
		break;
	}
	case 5:
	{
		player = new HarryPotter();
		cout << "You chose Harry Potter." << endl;
		return player;
		break;
	}
	}

}

void Play_Game::displayMenu()
{
	cout << "Please select one of the menu options below:" << endl;
	cout << "1) Start Game" << endl;
	cout << "2) Quit" << endl;

}


int Play_Game::getChoice()
{
	int choice;

	cin >> choice;

	while (choice < 1 || choice > 2)
	{
		cout << "Choice must be either 1 or 2. " << endl;
		cout << "Please re-enter choice. " << endl;
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> choice;
	}
	return choice;

}

void Play_Game::Menu()
{
	bool Quit = false;
	int Mchoice;

	std::cout << "Welcome to the Fantasy Fighting Game: Battle of Nightmares!" << endl;

	while (!Quit)
	{
		displayMenu();

		Mchoice = getChoice();

		switch (Mchoice)
		{
		case 1:
		{
			game();
			break;
		}
		case 2:
		{
			Quit = true;
			break;
		}
		default:
		{
			cout << "Error, bad input, quitting \n";
			break;
		}
		}
	}
}
