#pragma once
#include <list>
#include <Windows.h>

#include "Organism.h"

class Organism;

class World
{
private:
	int width;
	int height;
	int seniority;
	Organism*** map;	
	int freeCells;
	std::list<Organism*> activeTurn;
	std::list<Organism*> allOrganisms;
	int direction;

	HANDLE handle;
	
public:
	World();
	void allocateMap();

	int getWidth();
	int getHeight();
	int getSeniority();
	int getDirection();
	Organism* getMap(int x, int y);
	HANDLE getHandle();

	void setMap(int x, int y, Organism* Organism);
	void setFreeCells();

	unsigned int randBetween(int low, int high);
	void placeSpecies(unsigned char species, int quantity);
	void placeSpecies(unsigned char species, int x, int y);
	void placeFileAnimal(unsigned char species, int str, int sen, int x, int y, int cd = 0);
	void fillTheMap();
	void drawTurnState(bool& condition);
	void makeTurn();
	void actionAll();
	bool validLocation(int x, int y);
	void saveMap();
	void loadMap();
	void cleanUp();
	~World();
};