#pragma once
#include "Biome.h"
#include<iostream>

class biome_stack :
	public Biome
{
public:
	biome_stack();

	biome_stack(const unsigned int max_biomes);

	void add_biome(Biome input, bool force_add = false);

	void increase_max_size(const unsigned int increase_by);

	enum skew {LOW, HIGH, NONE};

	Biome* fetch_biome(int difficulty_low, int difficulty_high, const skew = NONE);

	void cat_biomes();

	//Getter functions
	inline const int get_max_size() { return MAX_NUM_BIOME; };
	inline const int get_cur_size() { return cur_size; };

	

	~biome_stack();
private:

	//Divides biomes into groups based on difficulty
	void gen_difficulty_classes();
	bool dif_class_generated = false;

	struct diff_class
	{
		Biome *biomes;
		int MAX = 0;
	};
	
	Biome null_biome;

	diff_class *biome_diff;
	Biome *all_def_biome;
	int MAX_NUM_BIOME;
	int cur_size;
};

