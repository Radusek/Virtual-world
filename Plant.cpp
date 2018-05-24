#include "Plant.h"



Plant::Plant(unsigned char sign, int str, int sen, Location loc, World* wrld) : Organism(sign, str, 0, sen, loc, wrld)
{
}

void Plant::action()
{
	int r = rand() % 20;
	if (r == 0) {
		int possibleCells = 0;
		int x = location.x, y = location.y;
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if ((i == 0 && j) || (j == 0 && i)) {
					if (world->validLocation(x + j, y + i)) {
						if (world->getMap(x + j, y + i) == nullptr) possibleCells++;
					}
				}
			}
		}
		if (possibleCells) {
			r = rand() % possibleCells;

			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					if ((i == 0 && j) || (j == 0 && i)) {
						if (world->validLocation(x + j, y + i)) {
							if (world->getMap(x + j, y + i) == nullptr) {
								if (r) r--;
								else {
									world->placeSpecies(getClassSign(), x + j, y + i);
									i = 2;
									j = 2;
								}
							}
						}
					}
				}
			}
		}
	}
}

void Plant::drawRepresentation()
{
	SetConsoleTextAttribute(world->getHandle(), 0x2);
	printf("%c", getClassSign() - 0x20);
}


Plant::~Plant()
{
}
