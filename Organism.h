#pragma once
#include "World.h"
#include "Location.h"

class World;

class Organism
{
protected:
	int strength;
	const int initiative;
	const int seniority;
	Location location;
	World* world;
	unsigned char classSign;
	bool defeated;
public:
	Organism(unsigned char sign, int str, int ini, int sen, Location loc, World*  world);
	int getStrength();
	int getInitiative();
	int getSeniority();
	int getLocationX();
	int getLocationY();
	unsigned char getClassSign();
	bool getDefeated();
	virtual int getData();

	void setLocation(int x, int y);
	void setDefeated();
	void ateGuarana();

	virtual void action() = 0;
	virtual void collision(Organism* attacker);
	virtual void drawRepresentation() = 0;
	virtual ~Organism();
};