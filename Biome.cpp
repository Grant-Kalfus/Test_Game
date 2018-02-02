//Biome.h || Grant Kalfus || Class to define biomes

#include<iostream>
#include "Biome.h"
#include "helperFunctions.h"

Biome::Biome()
{
	BiomeID = -1;
	difficulty = -1;
	name = "NULL";
	hasPlants = false;
	isUnderground = false;
	hasWater = NO;
	//weather = CLEAR;
	//time = DAWN;
	specialMod = "NONE";
}

Biome::Biome(int difficulty, string Name, bool Plants, bool Underground, waterContent Water, string sMod)
{
	BiomeID = -2;
	Biome::difficulty = difficulty;
	name = Name;
	hasPlants = Plants;
	isUnderground = Underground;
	
	if (Water == RANDWATER)
		hasWater = waterContent(getRand(0, 2));
	else
		hasWater = Water;
	
/*	if (cweather == RANDWEATHER)
		weather = weatherCond(getRand(0, 5));
	else
		weather = cweather;

	if (ctime == RANDTIME)
		time = timeT(getRand(0, 3));
	else
		time = ctime;
*/

	specialMod = sMod;
}

Biome& Biome::operator=(const Biome &b)
{
	this->BiomeID = b.BiomeID;
	this->difficulty = b.difficulty;
	this->hasPlants = b.hasPlants;
	this->hasWater = b.hasWater;
	this->isUnderground = b.isUnderground;
	this->name = b.name;
	this->specialMod = b.specialMod;
	return *this;
	//this->time = b.time;
	//this->weather = b.weather;
}

/*
Biome* Biome::operator&()
{
	Biome *biome_p = NULL;
	biome_p->BiomeID = this->BiomeID;
	biome_p->difficulty = this->difficulty;
	biome_p->hasPlants = this->hasPlants;
	biome_p->hasWater = this->hasWater;
	biome_p->isUnderground = this->isUnderground;
	biome_p->name = this->name;
	biome_p->specialMod = this->specialMod;
	return biome_p;
}
*/


