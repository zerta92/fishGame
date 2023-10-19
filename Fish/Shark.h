#ifndef SHARK_H
#define SHARK_H


#include "Fish.h"



class Shark : public Fish{
private:
	double energy;
	double size;
	int attack_strength;
	double range;
	Fish*target;
public:
	Shark(int , Model*);
	Shark(int, CartPoint, Model*);
	double get_speed();
	void start_attack(Fish* target);
	bool update();
	void show_status();




};
#endif