#pragma once
#include "Animal.h"
class Human :
	public Animal
{
private:
	int cooldown;
public:
	Human(Location loc, World * world);
	Human(int str, int sen, int cd, Location loc, World * world);
	int getData();
	void drawRepresentation();
	void action();
	~Human(); 
};

