#include "Dandelion.h"
#include "const.h"



Dandelion::Dandelion(Location loc, World * world) : Plant(DANDELION_SIGN, DANDELION_STR, world->getSeniority(), loc, world)
{
}

void Dandelion::action()
{
	for (int i = 0; i < 3; i++) Plant::action();
}


Dandelion::~Dandelion()
{
}
