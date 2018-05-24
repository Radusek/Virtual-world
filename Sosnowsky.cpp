#include <iostream>

#include "Sosnowsky.h"
#include "const.h"


Sosnowsky::Sosnowsky(Location loc, World * world) : Plant(SOSNOWSKY_SIGN, SOSNOWSKY_STR, world->getSeniority(), loc, world)
{
}

void Sosnowsky::action()
{
	int x = location.x, y = location.y;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i || j) {
				if (world->validLocation(x + j, y + i)) {
					if (world->getMap(x + j, y + i)) {
						if (world->getMap(x + j, y + i)->getClassSign() <= 0x60) {
							std::cout << "barszcz zabil (" << world->getMap(x + j, y + i)->getClassSign() << ")" << std::endl;
							world->getMap(x + j, y + i)->setDefeated();
							world->setMap(x + j, y + i, nullptr);
							world->setFreeCells();
						}
					}
				}
			}
		}
	}
	Plant::action();
}


void Sosnowsky::collision(Organism * attacker)
{
	world->setMap(attacker->getLocationX(), attacker->getLocationY(), nullptr);
	setDefeated();
	attacker->setDefeated();
	world->setMap(location.x, location.y, nullptr);
	std::cout << "zjedzono BARSZCZ (" << attacker->getClassSign() << ")" << std::endl;
	world->setFreeCells();
	world->setFreeCells();
}

void Sosnowsky::drawRepresentation()
{
	SetConsoleTextAttribute(world->getHandle(), 0xC);
	printf("%c", getClassSign() - 0x20);
}

Sosnowsky::~Sosnowsky()
{
}
