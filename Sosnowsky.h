#pragma once
#include "Plant.h"
class Sosnowsky :
	public Plant
{
public:
	Sosnowsky(Location loc, World * world);
	void action();
	void collision(Organism* attacker);
	void drawRepresentation();
	~Sosnowsky();
};

