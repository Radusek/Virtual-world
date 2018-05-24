#include <iostream>
#include "Animal.h"


Animal::Animal(unsigned char sign, int str, int ini, int sen, Location loc, World* wrld) : Organism(sign, str, ini, sen, loc, wrld)
{
}

void Animal::action()
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

void Animal::collision(Organism * attacker)
{
	
	if (attacker->getClassSign() == getClassSign()) {
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if ((i == 0 && j) || (j == 0 && i)) {
					int x = location.x, y = location.y;
					if (world->validLocation(x + j, y + i)) {
						if (world->getMap(x + j, y + i) == nullptr) {
							world->placeSpecies(getClassSign(), x + j, y + i);
							std::cout << "(" << classSign << ")" << " sie rozmnozyl" << std::endl;
							i = 2;
							j = 2;
						}
					}
				}
			}
		}
	}
	else {
		Organism::collision(attacker);
	}
	
}

void Animal::drawRepresentation()
{
	SetConsoleTextAttribute(world->getHandle(), 0xE);
	printf("%c", getClassSign());
}


int Animal::countPossibilities()
{
	int possibleMoves = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++)
			if ((i == 0 && j) || (j == 0 && i)) {
				int dX = j, dY = i;
				int x = location.x + dX, y = location.y + dY;
				if (world->validLocation(x, y)) {
					possibleMoves++;
				}
			}
	}
	return possibleMoves;
}

Animal::~Animal()
{
}
