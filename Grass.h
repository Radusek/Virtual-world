#pragma once
#include "Plant.h"
class Grass :
	public Plant
{
public:
	Grass(Location loc, World * world);
	~Grass();
};

