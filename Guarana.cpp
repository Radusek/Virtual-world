#include <iostream>
#include "Guarana.h"
#include "const.h"


Guarana::Guarana(Location loc, World * world) : Plant(GUARANA_SIGN, GUARANA_STR, world->getSeniority(), loc, world)
{
}

void Guarana::collision(Organism * attacker)
{
	world->setMap(attacker->getLocationX(), attacker->getLocationY(), nullptr);
	attacker->setLocation(location.x, location.y);
	world->setMap(location.x, location.y, attacker);
	setDefeated();
	world->setFreeCells();
	attacker->ateGuarana();
	std::cout << "guarana zjedzona (" << attacker->getClassSign() << ")" << std::endl;
}

void Guarana::drawRepresentation()
{
	SetConsoleTextAttribute(world->getHandle(), 0xA);
	printf("%c", getClassSign() - 0x20);
}


Guarana::~Guarana()
{
}
