#pragma once
#include "Animal.h"
class Fox :
	public Animal
{
public:
	Fox(Location loc, World * world);
	Fox(int str, int sen, Location loc, World* world);
	void action();
	~Fox();
};

