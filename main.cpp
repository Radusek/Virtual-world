#pragma once
#include <ctime>

#include "const.h"
#include "World.h"

int main() {
	SetConsoleTitle("Radoslaw Rychlik 165422");
	srand(time(NULL));
	World* world = new World();
	delete world;
	return 0;
}