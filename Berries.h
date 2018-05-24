#pragma once
#include "Plant.h"
class Berries :
	public Plant
{
public:
	Berries(Location loc, World * world);
	void collision(Organism* attacker);
	void drawRepresentation();
	~Berries();
};

