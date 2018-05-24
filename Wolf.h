#pragma once
#include "Animal.h"
class Wolf :
	public Animal
{
public:
	Wolf(Location loc, World* world);
	Wolf(int str, int sen, Location loc, World* world);
	~Wolf();
};

