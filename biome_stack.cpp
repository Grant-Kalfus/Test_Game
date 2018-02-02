#include "biome_stack.h"

biome_stack::biome_stack() {
	MAX_NUM_BIOME = 2;
	all_def_biome = new Biome[MAX_NUM_BIOME];
	cur_size = 0;
}

biome_stack::biome_stack(const unsigned int max_biomes)
{
	if (max_biomes < 1) {
		std::cerr << "ERROR: cannot have max biomes less than one. Recieved value: " << max_biomes << ".\n";
		abort();
	}

	MAX_NUM_BIOME = max_biomes + 1;
	all_def_biome = new Biome[MAX_NUM_BIOME];
	cur_size = 0;

	biome_diff = new diff_class[get_max_diff()];
}

void biome_stack::add_biome(Biome input, bool force_add) {
	if (cur_size + 1 == MAX_NUM_BIOME && force_add == false) {
		std::cerr << "ERROR: cannot add more than max biomes: " << MAX_NUM_BIOME - 1 << ".\nTo increase the size forcefully, enable force add.\n";
		return;
	}
	else if (cur_size + 1 == MAX_NUM_BIOME) {
		increase_max_size(1);
	
		all_def_biome[cur_size + 1] = input;
		cur_size++;

	} else {
		input.set_id(cur_size);
		all_def_biome[cur_size + 1] = input;
		cur_size++;
	}

}

void biome_stack::increase_max_size(const unsigned int increase_by)
{
	if (increase_by <= 0) {
		std::cerr << "ERROR: cannot increase size by less than 1.\nTo decrease the size forcefully, enable force overwite.\n";
		return;
	}
	else {
		Biome *temp;
		int NEW_SIZE = MAX_NUM_BIOME + increase_by;

		temp = new Biome[NEW_SIZE];

		for (int i = 0; i < MAX_NUM_BIOME; i++)
			temp[i] = all_def_biome[i];

		delete[] all_def_biome;

		all_def_biome = new Biome[NEW_SIZE];

		for (int i = 0; i < MAX_NUM_BIOME; i++)
			all_def_biome[i] = temp[i];

		delete[] temp;

		MAX_NUM_BIOME = NEW_SIZE;
	}
}

Biome* biome_stack::fetch_biome(int difficulty_low, int difficulty_high, const skew skew_var)
{
	Biome *temp = NULL;
	if (dif_class_generated == false) { std::cerr << "ERROR: Difficulty classes not generated! Run cat_biomes().\n"; Biome NULL_b; return &NULL_b;}

	if (difficulty_low < 0 || difficulty_low > get_max_diff()) {
		std::cerr << "ERROR: difficulty_low is out of bounds! Value entered: " << difficulty_low << ".\n";
		Biome NULL_b;
		return &NULL_b;
	}
	if (difficulty_high < difficulty_low || difficulty_high > get_max_diff()) {
		std::cerr << "ERROR: difficulty_high is higher than difficulty_low or max difficulty! Value entered: " << difficulty_high << ".\n";
		Biome NULL_b;
		return &NULL_b;
	}

	int avg = round((static_cast<double>(difficulty_high + difficulty_low) / 2.0));

	
	if (skew_var == LOW) {
		int cur_diff = getRand(difficulty_low, avg);
		int timeout = 0;
		while (biome_diff[cur_diff].MAX == 0) {
			cur_diff = getRand(difficulty_low, avg);
			timeout++;
			if (timeout == 50) { std::cerr << "ERROR: No biome of difficulty " << cur_diff << " exists from " << difficulty_low << "to " << avg << ".\n";Biome NULL_b; return &NULL_b;}
		}

		if (biome_diff[cur_diff].MAX > 1) {
			int rand = getRand(0, biome_diff[cur_diff].MAX - 1);
			
			temp = &biome_diff[cur_diff].biomes[rand];
			return temp;
		}
				else {
			temp = &biome_diff[cur_diff].biomes[0];
			return temp;
		}
	}
	else if (skew_var == HIGH) {
		int cur_diff = getRand(avg, difficulty_high);
		int timeout = 0;
		while (biome_diff[cur_diff].MAX == 0) {
			cur_diff = getRand(avg, difficulty_high);
			timeout++;
			if (timeout == 50) { std::cerr << "ERROR: No biome of difficulty " << cur_diff << " exists from " << avg << "to " << difficulty_high << ".\n"; Biome NULL_b; return &NULL_b; }
		}

		if (biome_diff[cur_diff].MAX > 1) {
			int rand = getRand(0, biome_diff[cur_diff].MAX - 1);
			return &biome_diff[cur_diff].biomes[rand];
		}
		else {
			return &biome_diff[cur_diff].biomes[0];
		}
	}
	else {
		int cur_diff = getRand(difficulty_low, difficulty_high);
		int timeout = 0;
		while (biome_diff[cur_diff].MAX == 0) {
			cur_diff = getRand(difficulty_low, difficulty_high);
			timeout++;
			if (timeout == 50) { std::cerr << "ERROR: No biome of difficulty " << cur_diff << " exists from " << difficulty_low << "to " << difficulty_high << ".\n"; Biome NULL_b; return &NULL_b; }
		}
		return &biome_diff[cur_diff].biomes[0];
	}
}

void biome_stack::cat_biomes()
{
	if (dif_class_generated == true) { std::cerr << "ERROR: Difficulty class already generated! Make sure to have all biomes declared before running.\n"; return; }
	gen_difficulty_classes();
	dif_class_generated = true;
}



biome_stack::~biome_stack()
{
	if(all_def_biome != NULL) {
		delete[] all_def_biome;
	}

	if (dif_class_generated) {
		for (int i = 0; i < get_max_diff(); i++) {
			if (biome_diff[i].biomes)
				delete[] biome_diff[i].biomes;
		}
	}
	
	delete[] biome_diff;
}

//Divides biomes into groups based on difficulty
void biome_stack::gen_difficulty_classes()
{
	//First loop goes from zero to max defined difficulty
	for (int i = 0; i < get_max_diff(); i++) {
		
		//Second loop finds the space needed to hold biomes of difficulty [i]
		for (int j = 0; j < cur_size; j++) {
			if (all_def_biome[j].get_difficulty() == i)
				biome_diff[i].MAX++;
		}
		//Allocates space per biomes 
		biome_diff[i].biomes = new Biome[biome_diff[i].MAX];
		
		//Third loop iterates from zero to the max number of different biomes of difficulty [i]
		for (int j = 0; j < biome_diff[j].MAX; j++) {

			//Fourth loop finds the biomes of difficulty [i] and adds them to the array. 
			for (int k = 0; k < cur_size; k++) {
				if (all_def_biome[k].get_difficulty() == i)
					biome_diff[i].biomes[j] = all_def_biome[k];
			} 
		}
	}
}
