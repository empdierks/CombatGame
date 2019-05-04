// Author: Emily Dierks
// Date: 07/29/17
// Description: This program creates the menu and game play implementation for the Fantasy Combat Game.
// User will select two fighters, attack and defend, decrement health (HP), and continue until one
// fighter's health (HP) hits 0.

#ifndef PLAY_GAME_HPP
#define PLAY_GAME_HPP
#include "Creature.hpp"

class Play_Game {

private:
	Creature *player1;
	Creature *player2;
	int round;

public:
	Play_Game();
	void game();
	Creature* playerSelection();
	void displayMenu();
	int getChoice();
	void Menu();
};
#endif
