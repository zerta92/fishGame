#ifndef MODEL_H
#define MODEL_H


#include <iostream>
#include "GameObject.h"
#include "Fish.h"
#include "Cave.h"
#include "CoralReef.h"
#include "Tuna.h"
#include"Shark.h"
#include<list>////
#include "Sharknado.h"
//#include <fstream>

class View;
class Tuna;
class Cave;
class Sharknado;

class Model {
private:
	int time;

	//GameObject **object_ptrs;
	//int num_objects;
	//Fish** fish_ptrs;
	//int num_fish;
	//Cave** cave_ptrs;
	//int num_caves;
	//CoralReef** reef_ptrs;
	//int num_reefs;

protected:
	std::list<GameObject*> object_ptrs;
	std::list<Fish*> fish_ptrs;
	std::list<Cave*> cave_ptrs;
	std::list<CoralReef*> reef_ptrs;
	std::list<GameObject*> active_ptrs;
	std::list<Sharknado*> sharknado_ptrs;
public:
	Model();

	~Model();

	Fish* get_Fish_ptr(int id_num);

	CoralReef* get_CoralReef_ptr(int id_num);

	Cave*	get_Cave_ptr(int id_num);

	bool update();

	void display(View&view);

	void show_status();

	Tuna* find_mate(Tuna *mating_dude);

	void create_tuna(Cave *home, Model*world);

	int get_time();

	CartPoint rand_point();

	void add_pointer(GameObject* ptr);

	void remove_pointer(GameObject *ptr, int id);

	//GameObject* unhidden_pointer();
	std::list<Fish*> unhidden_pointer();

	Sharknado* get_sharknado_ptr();

	//void save(std::ofstream& file);

};

#endif