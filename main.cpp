#include<time.h> 
#include<iomanip>
#include<iostream>
#include<fstream>
#include<random>
#include<string>
#include <stdio.h>   
#include <stdlib.h> 
#include"Tile.h"
#include"biome_stack.h"

using namespace std;

void main() {
	//Get seed for random number generation
	srand(getSeed());
	Biome plains(0, "Plains", true, false, Biome::NO, "NONE");
	Biome forest(1, "Forest", true, false, Biome::NO, "NONE");
	Biome cave(2, "Cave", false, true, Biome::SOME, "NONE");
	Biome swamp(3, "Swamp", true, false, Biome::YES, "NONE");
	Biome jungle(4, "Jungle", true, false, Biome::YES, "NONE");
	Biome ruins(5, "Ruins", true, false, Biome::SOME, "NONE");
	Biome desert(6, "Desert", false, false, Biome::NO, "NONE");
	Biome mountain(7, "Mountain", false, false, Biome::NO, "NONE");
	Biome temple(8, "Temple", false, true, Biome::SOME, "NONE");
	biome_stack myStack(9);
	
	myStack.add_biome(plains);
	myStack.add_biome(forest);
	myStack.add_biome(cave);
	myStack.add_biome(swamp);
	myStack.add_biome(jungle);
	myStack.add_biome(ruins);
	myStack.add_biome(desert);
	myStack.add_biome(mountain);
	myStack.add_biome(temple);

	myStack.cat_biomes();
	for (int i = 0; i < 20; i++) {
		Biome * testBiome = NULL;
		testBiome = myStack.fetch_biome(0, 3);
		cout << testBiome->get_name() << endl;
	}

	cout << "Done!\n";
	

	
}
