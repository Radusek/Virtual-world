#include <cstdio>
#include <iostream>

#include "const.h"
#include "Organism.h"


Organism::Organism(unsigned char sign, int str, int ini, int sen, Location loc, World* wrld)
	: classSign(sign), strength(str), initiative(ini), seniority(sen), location(loc), world(wrld), defeated(false) {
}

int Organism::getStrength()
{
	return strength;
}

int Organism::getInitiative()
{
	return initiative;
}

int Organism::getSeniority()
{
	return seniority;
}

int Organism::getLocationX()
{
	return location.x;
}

int Organism::getLocationY()
{
	return location.y;
}

unsigned char Organism::getClassSign()
{
	return classSign;
}

bool Organism::getDefeated()
{
	return defeated;
}

int Organism::getData()
{
	return 0;
}

void Organism::setLocation(int x, int y)
{
	location.x = x;
	location.y = y;
}

void Organism::setDefeated()
{
	defeated = true;
}

void Organism::ateGuarana()
{
	strength += 3;
}

void Organism::collision(Organism* attacker)
{
	printf("(%c) %d zaatakowal %d (%c) ", attacker->getClassSign(), attacker->getSeniority(), seniority, getClassSign() >= 0x61 ? getClassSign() - 0x20 : getClassSign());
	world->setMap(attacker->getLocationX(), attacker->getLocationY(), nullptr);
	if (attacker->getStrength() < strength) {
		attacker->setDefeated();
		std::cout << "agresor polegl";
	}
	else {
		attacker->setLocation(location.x, location.y);
		world->setMap(location.x, location.y, attacker);
		setDefeated();
		std::cout << "agresor zwyciezyl";
	}
	std::cout << std::endl;
	world->setFreeCells();
}

void Organism::drawRepresentation()
{
}

Organism::~Organism()
{
}