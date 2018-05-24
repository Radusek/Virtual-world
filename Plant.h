#pragma once
#include "Organism.h"
class Plant :
	public Organism
{
public:
	Plant(unsigned char sign, int str, int sen, Location loc, World* wrld);
	void action();
	void drawRepresentation();
	virtual ~Plant();
};

