#include <iostream>
#include "Antilope.h"
#include "const.h"


Antilope::Antilope(Location loc, World * world) : Animal(ANTILOPE_SIGN, ANTILOPE_STR, ANTILOPE_INI, world->getSeniority(), loc, world)
{
}

Antilope::Antilope(int str, int sen, Location loc, World * world) : Animal(ANTILOPE_SIGN, str, ANTILOPE_INI, sen, loc, world)
{
}

void Antilope::action()
{
	int possibleMoves = countPossibilities(2);

	if (possibleMoves) {
		int randomizedDirection = rand() % possibleMoves;
		int x = location.x, y = location.y;

		for (int i = -2; i <= 2; i++) {
			for (int j = -2; j <= 2; j++) {
				if (abs(i) + abs(j) == 2) {
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
							i = 3;
							j = 3;
						}
					}
				}
			}
		}
	}
}

void Antilope::collision(Organism * attacker)
{
	if (countPossibilities(1) && getClassSign() != attacker->getClassSign()) {
		int r = rand() % 2;
		if (r) {
			int randomizedDirection = rand() % countPossibilities(1);
			int x = location.x, y = location.y;

			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if ((i == 0 && j) || (j == 0 && i)) {
						if (world->validLocation(x + j, y + i)) {
							if (world->getMap(x + j, y + i) == nullptr) {
								if (randomizedDirection) randomizedDirection--;
								else {
									world->setMap(x + j, y + i, this);
									world->setMap(x, y, nullptr);
									setLocation(x + j, y + i);
									i = 2;
									j = 2;
								}
							}
						}
					}
				}
			}
			std::cout << "antylopa uciekla" << std::endl;
		}
		else Animal::collision(attacker);
	}
	else Animal::collision(attacker);
}

int Antilope::countPossibilities(int range)
{
	int possibleMoves = 0;
	for (int i = -range; i <= range; i++) {
		for (int j = -range; j <= range; j++)
			if (abs(i) + abs(j) == range) {
				int dX = j, dY = i;
				int x = location.x + dX, y = location.y + dY;
				if (world->validLocation(x, y)) {
					if (range == 2) possibleMoves++;
					else if (world->getMap(x, y) == nullptr) possibleMoves++;
				}
			}
	}
	return possibleMoves;
}




Antilope::~Antilope()
{
}
