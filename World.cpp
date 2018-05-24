#include <iostream>
#include <cstdio>
#include <conio.h>
#include <fstream>

#include "World.h"
#include "Location.h"
#include "const.h"
#include "species.h"


World::World() : seniority(INT_MAX), handle(GetStdHandle(STD_OUTPUT_HANDLE))
{
	printf("Enter map's size (n x m): ");
	std::cin >> width >> height;
	allocateMap();
	freeCells = width * height;
	this->fillTheMap();
}

void World::allocateMap()
{
	map = new Organism**[height];
	for (int i = 0; i < height; i++) {
		map[i] = new Organism*[width];
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			map[i][j] = NULL;
		}
	}
}

int World::getWidth()
{
	return width;
}

int World::getHeight()
{
	return height;
}

int World::getSeniority()
{
	return seniority--;
}

int World::getDirection()
{
	return direction;
}

Organism* World::getMap(int x, int y)
{
	return map[y][x];
}

HANDLE World::getHandle()
{
	return handle;
}

void World::setMap(int x, int y, Organism* Organism)
{
	map[y][x] = Organism;
}

void World::setFreeCells()
{
	freeCells++;
}

unsigned int World::randBetween(int low, int high)
{
	int values = high - low + 1;
	return 7919*rand() % values + low;
}

void World::placeSpecies(unsigned char species, int quantity)
{
	for (int k = 0; k < quantity; k++) {
		int randSpot = randBetween(0, freeCells - 1);
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (randSpot) {
					if (map[i][j] == NULL) randSpot--;
				}
				else if (map[i][j] == NULL) {
					placeSpecies(species, j, i);
					i = height - 1;
					j = width - 1;
				}
			}
		}
	}
}

void World::placeSpecies(unsigned char species, int x, int y)
{
	Location loc(x, y);
	switch (species) {
	case HUMAN_SIGN:
		map[y][x] = new Human(loc, this);
		break;
	case WOLF_SIGN:
		map[y][x] = new Wolf(loc, this);
		break;
	case SHEEP_SIGN:
		map[y][x] = new Sheep(loc, this);
		break;
	case FOX_SIGN:
		map[y][x] = new Fox(loc, this);
		break;
	case TORTOISE_SIGN:
		map[y][x] = new Tortoise(loc, this);
		break;
	case ANTILOPE_SIGN:
		map[y][x] = new Antilope(loc, this);
		break;
	case GRASS_SIGN:
		map[y][x] = new Grass(loc, this);
		break;
	case DANDELION_SIGN:
		map[y][x] = new Dandelion(loc, this);
		break;
	case GUARANA_SIGN:
		map[y][x] = new Guarana(loc, this);
		break;
	case BERRIES_SIGN:
		map[y][x] = new Berries(loc, this);
		break;
	case SOSNOWSKY_SIGN:
		map[y][x] = new Sosnowsky(loc, this);
		break;
	}
	freeCells--;
	allOrganisms.push_front(map[y][x]);
}

void World::placeFileAnimal(unsigned char species, int str, int sen, int x, int y, int cd)
{
	Location loc(x, y);
	switch (species) {
	case HUMAN_SIGN:
		map[y][x] = new Human(str, sen, cd, loc, this);
		break;
	case WOLF_SIGN:
		map[y][x] = new Wolf(str, sen, loc, this);
		break;
	case SHEEP_SIGN:
		map[y][x] = new Sheep(str, sen, loc, this);
		break;
	case FOX_SIGN:
		map[y][x] = new Fox(str, sen, loc, this);
		break;
	case TORTOISE_SIGN:
		map[y][x] = new Tortoise(str, sen, loc, this);
		break;
	case ANTILOPE_SIGN:
		map[y][x] = new Antilope(str, sen, loc, this);
		break;
	}
	freeCells--;
}

void World::fillTheMap()
{
	int quantity = (width*height / 3) / SPECIES;

	placeSpecies(HUMAN_SIGN, 1);
	placeSpecies(WOLF_SIGN, quantity);
	placeSpecies(SHEEP_SIGN, quantity);
	placeSpecies(TORTOISE_SIGN, quantity);
	placeSpecies(FOX_SIGN, quantity);
	placeSpecies(ANTILOPE_SIGN, quantity);
	placeSpecies(GRASS_SIGN, quantity);
	placeSpecies(DANDELION_SIGN, quantity);
	placeSpecies(GUARANA_SIGN, quantity);
	placeSpecies(BERRIES_SIGN, quantity);
	placeSpecies(SOSNOWSKY_SIGN, quantity);
	
	makeTurn();
}

void World::drawTurnState(bool & condition)
{
	//RYSOWANIE PLANSZY
	if (condition) {
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (map[i][j] != nullptr) map[i][j]->drawRepresentation();
				else printf(" ");
			}
			printf("\n");
		}
		SetConsoleTextAttribute(handle, 7);
		for (int i = 0; i < width; i++) printf("-");
		printf("\n");
	}
	condition = 0;
}

void World::makeTurn()
{
	int direction = -1;
	bool condition = 1, ifArrow = 0;
	while (allOrganisms.size()) allOrganisms.pop_front();
	while (true) {
		//TWORZENIE LISTY TURY I SORTOWANIE
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				if (map[i][j]) {
					activeTurn.push_back(map[i][j]);
					allOrganisms.push_back(map[i][j]);
				}
			}
		}
		activeTurn.sort([](Organism* lhs, Organism* rhs) {
			if (lhs->getInitiative() > rhs->getInitiative()) return true;
			else if (lhs->getInitiative() < rhs->getInitiative()) return false;
			else if (lhs->getSeniority() > rhs->getSeniority()) return true;
			else return false;
		});

		drawTurnState(condition);

		//OBSLUGA KLAWIATURY
		this->direction = -1;
		char *arrow = 0;
		unsigned char key = _getch();
		if (key == ARROW) {
			condition = 1;
			ifArrow = 1;
			char right[] = "Right", left[] = "Left", up[] = "Up", down[] = "Down";
			key = _getch();
			switch (key) {
			case R_ARROW:
				direction = RIGHT;
				arrow = right;
				break;
			case L_ARROW:
				direction = LEFT;
				arrow = left;
				break;
			case U_ARROW:
				direction = UP;
				arrow = up;
				break;
			case D_ARROW:
				direction = DOWN;
				arrow = down;
				break;
			default:
				condition = 0;
				ifArrow = 0;
				break;
			}
		}
		else if (key == SPACEBAR) {
			//umiejetnosc czlowieka
			condition = 1;
			ifArrow = 0;
			this->direction = SPACEBAR;
		}
		else if (key == 's' || key == 'S') {
			ifArrow = 0;
			saveMap();
			printf("Stan gry zapisany\n");
		}
		else if (key == 'l' || key == 'L') {
			ifArrow = 0;
			loadMap();
			condition = 1;
		}
		else if (key == ESC) break;

		//INFORMACJA O NACISNIETYM KLAWISZU
		if (ifArrow) {
			printf("%s arrow pressed.\n", arrow);
			this->direction = direction;
		}
		else if (condition) printf("Umiejetnosc czlowieka\n");
		
		if (condition) {
			for (int i = 0; i < width; i++) printf("-");
			printf("\n");

			//RUCH OBIEKTOW
			actionAll();

			for (int i = 0; i < width; i++) printf("-");
			printf("\n");
		}

		//WYCZYSZCZENIE LISTY ORGANIZMOW
		while (allOrganisms.size()) {
			if (allOrganisms.front()){
				if (allOrganisms.front()->getDefeated()) {
					Organism* tmp = allOrganisms.front();
					delete tmp;
				}
			}
			allOrganisms.pop_front();
		}
	}
}

void World::actionAll()
{
	while (activeTurn.size()) {
		if (activeTurn.front()->getDefeated() == false) {
			activeTurn.front()->action();
		}
		activeTurn.pop_front();
	}
}

bool World::validLocation(int x, int y)
{
	return x >= 0 && x < width && y >= 0 && y < height;
}

void World::saveMap()
{
	std::ofstream file("save.txt");
	file << width << std::endl;
	file << height << std::endl;
	file << seniority << std::endl;
	int n = allOrganisms.size();
	file << n << std::endl;
	for (int i = 0; i < n; i++) {
		Organism* tmp = allOrganisms.front();
		unsigned char sgn = tmp->getClassSign();

		file << sgn << std::endl;
		if (sgn < 0x61) file << tmp->getStrength() << std::endl;
		file << tmp->getSeniority() << std::endl;
		file << tmp->getLocationX() << std::endl;
		file << tmp->getLocationY() << std::endl;
		if (sgn == HUMAN_SIGN) file << tmp->getData() << std::endl;

		allOrganisms.pop_front();
	}
	file.close();
}

void World::loadMap()
{
	std::ifstream file("save.txt");
	int w = 0, h = 0, s, n;
	file >> w;
	file >> h;
	file >> s;
	file >> n;
	if (w && h) {
		system("cls");
		cleanUp();
		while (allOrganisms.size()) allOrganisms.pop_front();
		while (activeTurn.size()) activeTurn.pop_front();
		width = w;
		height = h;
		allocateMap();
		seniority = s;
		freeCells = w * h;

		unsigned char sgn;
		int sen = 0, x = 0, y = 0, str = 0, cd = 0;
		for (int i = 0; i < n; i++) {		
			file >> sgn;
			if (sgn < 0x61) file >> str;
			file >> sen;
			file >> x;
			file >> y;
			if (sgn == HUMAN_SIGN) file >> cd;

			if (sgn < 0x61) placeFileAnimal(sgn, str, sen, x, y, cd);
			else placeSpecies(sgn, x, y);
		}
	}
	file.close();
}

void World::cleanUp()
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (map[i][j]) delete map[i][j];
		}
	}
	for (int i = 0; i < height; i++) delete[] map[i];
	delete[] map;
}

World::~World()
{
	cleanUp();
}