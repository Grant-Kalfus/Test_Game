//Biome.h || Grant Kalfus || Class to define biomes

using namespace std;

#pragma once
#include<string>
#include"helperFunctions.h"
class Biome
{
public:
	enum waterContent { YES, NO, SOME, RANDWATER };
	enum weatherCond { CLEAR, RAINY, STORMY, FOGGY, EERIE, SNOWY, RANDWEATHER};
	enum timeT { DAWN, NOON, DUSK, MIDNIGHT, RANDTIME };

	Biome();

	//Usage: Biome ID, Biome Name, If its underground, if it can have water, what the weather conditions are, the current time, and any special modifiers.
	Biome(int difficulty, string Name, bool Plants, bool Underground, waterContent Water, string sMod);
	
	//Opperator Overloads
	Biome& Biome::operator=(const Biome &b);


	//Getter functions:
	inline const int get_difficulty() { return difficulty; };
	inline const int get_biome_id() { return BiomeID; };
	inline const string get_name() { return name; };
	inline const bool get_has_plants() { return hasPlants; };
	inline const bool get_is_underground() { return isUnderground; };
	inline const waterContent get_water_lvl() { return hasWater; };
	//inline const weatherCond get_weather() { return weather; };
	//inline const timeT get_time() { return time; };
	inline const string get_special_mod() { return specialMod; };
	inline const int get_max_diff() const { return MAX_DIFFICULTY; };
	inline void set_id(const int id) { BiomeID = id; };


protected:


private:


	const int MAX_DIFFICULTY = 10;
	int difficulty;
	int BiomeID;
	string name;
	bool hasPlants;
	bool isUnderground;
	waterContent hasWater;
	//weatherCond weather;
	//timeT time;
	string specialMod;
};

