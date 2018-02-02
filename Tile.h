#pragma once
#include"structures.h"
#include"helperFunctions.h"
#include<iostream>
class Tile : public structures {
public:
	//Constructor
	Tile();
	
	//Destructor
	~Tile();

	//Generates a fixed number of structures denoted by number
	void genStructures(unsigned int number);

	//Generates structures. Min number of structures to generate is start, max is end.
	//ex: genStructures(0, 3) generates zero to three structures
	void genStructures(unsigned int start, unsigned int end);
	

	
private:
	structures *numberS;
	unsigned int SIZE_S;
};