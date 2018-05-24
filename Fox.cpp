#include "Fox.h"
#include "const.h"



Fox::Fox(Location loc, World * world) : Animal(FOX_SIGN, FOX_STR, FOX_INI, world->getSeniority(), loc, world)
{
}

Fox::Fox(int str, int sen, Location loc, World * world) : Animal(FOX_SIGN, str, FOX_INI, sen, loc, world)
{
}


void Fox::action()
{
	//OKREŒLENIE MO¯LIWOŒCI RUCHU
	int possibleMoves = countPossibilities();

	if (possibleMoves) {
		int randomizedDirection = rand() % possibleMoves;
		int x = location.x, y = location.y;

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if ((i == 0 && j) || (j == 0 && i)) {
					if (world->validLocation(x + j, y + i)) {
						if (randomizedDirection) randomizedDirection--;
						else {
							if (world->getMap(x + j, y + i)) {
								if(getClassSign() == world->getMap(x + j, y + i)->getClassSign() || world->getMap(x + j, y + i)->getStrength() < getStrength())
									world->getMap(x + j, y + i)->collision(this);
							}
							else {
								world->setMap(x + j, y + i, this);
								world->setMap(x, y, nullptr);
								setLocation(x + j, y + i);
							}
							i = 2;
							j = 2;
						}
					}
				}
			}
		}
	}
}




Fox::~Fox()
{
}
