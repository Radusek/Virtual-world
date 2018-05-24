#pragma once
#include "Animal.h"
class Tortoise :
	public Animal
{
public:
	Tortoise(Location loc, World * world);
	Tortoise(int str, int sen, Location loc, World* world);
	void action();
	void collision(Organism* attacker);
	~Tortoise();
};

