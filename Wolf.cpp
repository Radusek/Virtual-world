#include "Wolf.h"
#include "const.h"

Wolf::Wolf(Location loc, World* world) : Animal(WOLF_SIGN, WOLF_STR, WOLF_INI, world->getSeniority(), loc, world)
{
}

Wolf::Wolf(int str, int sen, Location loc, World* world) : Animal(WOLF_SIGN, str, WOLF_INI, sen, loc, world)
{
}

Wolf::~Wolf()
{
}
