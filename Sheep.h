#pragma once
#include "Animal.h"
class Sheep :
	public Animal
{
public:
	Sheep(Location loc, World* world);
	Sheep(int str, int sen, Location loc, World* world);
	~Sheep();
};

