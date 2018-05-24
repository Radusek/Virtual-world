#include <iostream>

#include "Berries.h"
#include "const.h"


Berries::Berries(Location loc, World * world) : Plant(BERRIES_SIGN, BERRIES_STR, world->getSeniority(), loc, world)
{
}

void Berries::collision(Organism* attacker)
{
	world->setMap(attacker->getLocationX(), attacker->getLocationY(), nullptr);
	setDefeated();
	attacker->setDefeated();
	world->setMap(location.x, location.y, nullptr);
	std::cout << "zjedzono jagody (" << attacker->getClassSign() << ")" << std::endl;
	world->setFreeCells();
	world->setFreeCells();
}

void Berries::drawRepresentation()
{
	SetConsoleTextAttribute(world->getHandle(), 0x4);
	printf("%c", getClassSign() - 0x20);
}


Berries::~Berries()
{
}
