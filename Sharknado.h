#ifndef SHARKNADO_H
#define SHARKNADO_H

#include<iostream>
#include"Model.h"
#include "GameObject.h"
using namespace std;



class Sharknado : public GameObject {

public:

	void wipe();

	std::list<Fish*> dead_ptrs;

	std::list<Fish*> test;

	int timer_of_doom;

	Sharknado(int, char, Model*);

	Model * world;


	virtual bool update();

	//void save(std::ofstream& file);



};

#endif