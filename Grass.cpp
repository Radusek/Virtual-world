#include "Grass.h"
#include "const.h"



Grass::Grass(Location loc, World * world) : Plant(GRASS_SIGN, GRASS_STR, world->getSeniority(), loc, world)
{
}


Grass::~Grass()
{
}
