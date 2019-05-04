# Author: Emily Dierks

proj3: proj3.o Barbarian.o BlueMen.o Creature.o HarryPotter.o Medusa.o Play_Game.o Vampire.o
	g++ proj3.o Barbarian.o BlueMen.o Creature.o HarryPotter.o Medusa.o Play_Game.o Vampire.o -o proj3

proj3.o: proj3.cpp Play_Game.cpp Play_Game.hpp
	g++ -c proj3.cpp

Barbarian.o: Barbarian.cpp Barbarian.hpp Creature.cpp Creature.hpp
	g++ -c Barbarian.cpp

BlueMen.o: BlueMen.cpp BlueMen.hpp Creature.cpp Creature.hpp
	g++ -c BlueMen.cpp

Creature.o: Creature.cpp Creature.hpp
	g++ -c Creature.cpp

HarryPotter.o: HarryPotter.cpp HarryPotter.hpp Creature.cpp Creature.hpp
	g++ -c HarryPotter.cpp

Medusa.o: Medusa.cpp Medusa.hpp Creature.cpp Creature.hpp
	g++ -c Medusa.cpp

Play_Game.o: Play_Game.cpp Play_Game.hpp Barbarian.cpp Barbarian.hpp BlueMen.cpp BlueMen.hpp HarryPotter.cpp HarryPotter.hpp Medusa.cpp Medusa.hpp\
 Vampire.cpp Vampire.hpp Creature.cpp Creature.hpp
	g++ -c Play_Game.cpp

Vampire.o: Vampire.cpp Vampire.hpp Creature.cpp Creature.hpp
	g++ -c Vampire.cpp

clean:
	rm *.o proj3
