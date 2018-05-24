#include <iostream>
#include "Tortoise.h"
#include "const.h"


Tortoise::Tortoise(Location loc, World * world) : Animal(TORTOISE_SIGN, TORTOISE_STR, TORTOISE_INI, world->getSeniority(), loc, world)
{
}

Tortoise::Tortoise(int str, int sen, Location loc, World * world) : Animal(TORTOISE_SIGN, str, TORTOISE_INI, sen, loc, world)
{
}

void Tortoise::action()
{
	int r = rand() % 4;
	if (r == 0) Animal::action();
}

void Tortoise::collision(Organism* attacker)
{
	if (attacker->getClassSign() == getClassSign() || attacker->getStrength() >= 5) Animal::collision(attacker);
	else std::cout << "Zolw odbil atak" << std::endl;
}


Tortoise::~Tortoise()
{
}
