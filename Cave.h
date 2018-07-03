#ifndef Cave_H
#define Cave_H

#include <iostream>
//#include <cmath>
#include "GameObject.h"
#include "Fish.h"

class Fish;

class Cave : public GameObject{

private:
	double space;

protected:
	char display_code;
	char state;

public:

	bool hide_fish(Fish *fish_to_hide);

	bool release_fish(Fish*fish_to_release);

	bool update();

	void show_status();

	Cave();

	Cave(int in_id, CartPoint in_loc);

	double get_space();


	//void save(std::ofstream& file);

	


};




#endif

