#pragma once
#include "Plant.h"
class Dandelion :
	public Plant
{
public:
	Dandelion(Location loc, World * world);
	void action();
	~Dandelion();
};

