#include"Tile.h"

Tile::Tile() {

}

Tile::~Tile() {
	if (numberS) 
		delete[] numberS;
}

void Tile::genStructures(unsigned int number)
{
	SIZE_S = number + 1;
	numberS = new structures[SIZE_S];
}

void Tile::genStructures(unsigned int start, unsigned int end)
{
	SIZE_S = getRand(start, end) + 1;
	numberS = new structures[SIZE_S];
}
