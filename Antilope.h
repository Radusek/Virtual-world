#pragma once
#include "Animal.h"

class Antilope :
	public Animal
{
public:
	Antilope(Location loc, World * world);
	Antilope(int str, int sen, Location loc, World* world);
	void action();
	void collision(Organism* attacker);
	int countPossibilities(int range);
	~Antilope();
};

