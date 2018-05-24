#pragma once
#include "Organism.h"
class Animal :
	public Organism
{
public:
	Animal(unsigned char sign, int str, int ini, int sen, Location loc, World * wrld);
	virtual void action();
	virtual void collision(Organism* attacker);
	void drawRepresentation();
	int countPossibilities();
	virtual ~Animal();
};

