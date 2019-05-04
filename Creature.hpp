// Author: Emily Dierks
// Date: 07/29/17
// Description: This program is the abstract base class for the fighters: Vampire, Barbarian,
// Blue Men, Medusa, and Harry Potter.  This class holds the pure virtual functions that the character
// classes will override

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <string>

class Creature {

protected:
	int HP;
	int Armor;
	std::string type;

public:
	virtual int attack() = 0;
	virtual int defend(int d) = 0;
	void setHP(int);
	int getHP();
	void setArmor(int);
	int getArmor();
	std::string getType();

};
#endif // !CREATURE_HPP




