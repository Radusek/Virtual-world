#pragma once
#include "Plant.h"
class Guarana :
	public Plant
{
public:
	Guarana(Location loc, World * world);
	void collision(Organism* attacker);
	void drawRepresentation();
	~Guarana();
};