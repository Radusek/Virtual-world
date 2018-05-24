#include "Sheep.h"
#include "const.h"


Sheep::Sheep(Location loc, World * world) : Animal(SHEEP_SIGN, SHEEP_STR, SHEEP_INI, world->getSeniority(), loc, world)
{
}

Sheep::Sheep(int str, int sen, Location loc, World * world) : Animal(SHEEP_SIGN, str, SHEEP_INI, sen, loc, world)
{
}

Sheep::~Sheep()
{
}
