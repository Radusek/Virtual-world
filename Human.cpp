#include <iostream>

#include "Human.h"
#include "const.h"



Human::Human(Location loc, World * world) : Animal(HUMAN_SIGN, HUMAN_STR, HUMAN_INI, world->getSeniority(), loc, world)
{
	cooldown = 0;
}

Human::Human(int str, int sen, int cd, Location loc, World * world) : Animal(HUMAN_SIGN, str, HUMAN_INI, sen, loc, world)
{
	cooldown = cd;
}

int Human::getData()
{
	return cooldown;
}

void Human::drawRepresentation()
{
	SetConsoleTextAttribute(world->getHandle(), 0xD);
	printf("%c", getClassSign());
}

void Human::action()
{
	if (cooldown) cooldown--;
	if (world->getDirection() >= 0 && world->getDirection() <= 3) {
		int dir = world->getDirection();
		int x = location.x, y = location.y;
		int dx = 0, dy = 0, range = 1;
		if (cooldown > 7) range = 2;
		else if (cooldown > 5) range = (rand() % 2) + 1;
		for (int i = range; i >= 1; i--) {
			if (dir == UP) dy = -i;
			else if (dir == DOWN) dy = i;
			else if (dir == LEFT) dx = -i;
			else if (dir == RIGHT) dx = i;
			if (world->validLocation(x + dx, y + dy)) break;
		}

		if (world->validLocation(x + dx, y + dy)) {
			if (world->getMap(x + dx, y + dy)) {
				world->getMap(x + dx, y + dy)->collision(this);
			}
			else {
				world->setMap(x + dx, y + dy, this);
				world->setMap(x, y, nullptr);
				setLocation(x + dx, y + dy);
			}
		}
		SetConsoleTextAttribute(world->getHandle(), 0xD);
		if (cooldown) std::cout << "umiejetnosc gotowa za " << cooldown << " tur" << std::endl;
	}
	else if (world->getDirection() == SPACEBAR){
		SetConsoleTextAttribute(world->getHandle(), 0xD);
		if (cooldown == 0) {
			std::cout << "rozpoczeto umiejetnosc czlowieka" << std::endl;
			cooldown = 11;
		}
		else std::cout << "mozesz uzyc umiejetnosci za " << cooldown << " tur" << std::endl;
	}
	SetConsoleTextAttribute(world->getHandle(), 7);
}

Human::~Human()
{
}
