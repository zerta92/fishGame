#ifndef Fish_H
#define Fish_H

#include <iostream>
#include "../Coordinates/CartPoint.h"
#include "../Coordinates/CartVector.h"
#include "../Reef/CoralReef.h"
#include "../Game/GameObject.h"
#include "../Cave/Cave.h"
#include <cmath>
// #include "Model.h"

class Cave;
class Model;

class Fish : public GameObject
{

private:
	double energy;

	double size;

	double prefeast_size;

	CartPoint destination;

	CartVector delta;

	CoralReef *reef;

	Cave *home;

	bool update_location();

	void setup_destination(CartPoint dest);

protected:
	char display_code;
	char state;
	Model *world;

public:
	Fish(char display_code, int size, Model *world);

	Fish(char display_code, int in_id, Cave *home, int size, Model *world);

	Fish(char display_code, int in_id, CartPoint p1, int size, Model *world);

	~Fish();

	double get_size();

	bool update();

	void start_hiding(Cave *destCave);

	virtual double get_speed() = 0;

	void show_status();

	void start_swimming(CartPoint dest);

	void start_eating(CoralReef *destReef);

	void float_in_place();

	bool is_hidden();

	virtual void start_attack(Fish *);

	virtual void start_mating(Fish *);

	void get_bitten(int attack_strength);

	bool is_alive();

	Cave *get_cave();

	char get_display();

	char get_state();

	// void save(std::ofstream& file);
};

#endif
