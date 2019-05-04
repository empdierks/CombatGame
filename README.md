# CombatGame: Battle of Nightmares!

Project Design
This is a fantasy combat game in which two players select a character and each round consists 
of one player defending and one player attacking until one character dies.  Each character has
different abilities and dice rolls to defend and attack.  The breakdown for each character is below:

Character     Attack      Defense     Armor   Strength Points
Vampire       1d12        1d6 (charm)   1       18
Barbarian     2d6         2d6           0       12
Blue Men      2d10        3d6           3       12 (mob)
Medusa        2d6 (glare) 1d6           3       8
Harry Potter  2d6         2d6           0       10/20 (Hogwarts)

Special Abilities
Charm: 50% chance opponent doesn't attack
Glare:  If rolls a 12 in attack, target looks into Medusa's eyes and turned to stone. Medusa wins unless used on Harry
Potter's first life, then Harry comes back to life.  If the Vampire's Charm activates along with Medusa's Glare, Charm trumps
the Glare.
Mob: For every 4 points of damage they lose 1 defense die. For instance, when at strenght 8 only have 2d6 defense
Hogwarts: If Harry dies then immediately recovers with total strength at 20. However if dies again them dead.

Technical Details
There is a Creature base class with inherited classes for the characters and a class to implement the game.  The Play_Game class
sets up a menu, dynamically allocates players, selects first attacker, displays round results and declares the victor.

The Creature baseclass sets up the inherited variables (HP, Armor, and type), the inherited attack & defend actions, and inherited
set and get functions.The sub-class Creature have overridden attack and defend functions to roll the appropriate dice and apply special abilities along
with applying defense and armor, and changing health.


