#include<time.h> 
#include<iomanip>
//HelperFunctions.cpp || Grant Kalfus || Implementation for core functions

#include<iostream>
#include<fstream>
#include<random>
#include<string>
#include <stdio.h>   
#include <stdlib.h> 
#include<math.h>

using namespace std;
#include"helperFunctions.h"

//Creates a seed for random number generation
unsigned int getSeed() {
	return static_cast<unsigned int>(time(NULL)); 
}

//Gets a random number
int getRand(int begin, int end) { 
	return rand() % end + begin; 
}

//Clears the console screen
void clearScreen(){
	cout << string(100, '\n');
}
