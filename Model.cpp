#include <iostream>
#include "Model.h"
#include "View.h"
#include <list>
#include "./Fish/Shark.h"
#include "./Fish/Tuna.h"
#include "./Game/GameObject.h"
#include <stdlib.h>

using namespace std;

class Tuna;

static int baby_tuna = 1;

Model::Model()
{
	this->time = 0;
	srand(get_time());
	double x = rand() % 21;
	double y = rand() % 21;

	Cave *c1 = new Cave(1, CartPoint(5, 1));
	Cave *c2 = new Cave(2, CartPoint(6, 2));

	Sharknado *sharknado = new Sharknado(0, 'B', this);

	Tuna *t1 = new Tuna(1, c1, this); // c1
	Tuna *t2 = new Tuna(2, c2, this);
	Tuna *t3 = new Tuna(3, c2, this); // c2
	Shark *s4 = new Shark(4, CartPoint(x, y), this);
	Shark *s5 = new Shark(5, CartPoint(x, y), this);

	CoralReef *cr1 = new CoralReef(1, CartPoint(1, 20));
	CoralReef *cr2 = new CoralReef(2, CartPoint(20, 1));
	CoralReef *cr3 = new CoralReef(3, CartPoint(20, 20));

	// SHARKNADO
	sharknado_ptrs.push_back(sharknado);

	// TUNA
	object_ptrs.push_back(t1);
	object_ptrs.push_back(t2);
	object_ptrs.push_back(t3);
	active_ptrs.push_back(t1);
	active_ptrs.push_back(t2);
	active_ptrs.push_back(t3);
	fish_ptrs.push_back(t1);
	fish_ptrs.push_back(t2);
	fish_ptrs.push_back(t3);

	// SHARK
	object_ptrs.push_back(s4);
	object_ptrs.push_back(s5);
	active_ptrs.push_back(s4);
	active_ptrs.push_back(s5);
	fish_ptrs.push_back(s4);
	fish_ptrs.push_back(s5);

	// REEF
	object_ptrs.push_back(cr1);
	object_ptrs.push_back(cr2);
	object_ptrs.push_back(cr3);
	active_ptrs.push_back(cr1);
	active_ptrs.push_back(cr2);
	active_ptrs.push_back(cr3);
	reef_ptrs.push_back(cr1);
	reef_ptrs.push_back(cr2);
	reef_ptrs.push_back(cr3);

	// CAVE
	object_ptrs.push_back(c1);
	object_ptrs.push_back(c2);
	cave_ptrs.push_back(c1);
	cave_ptrs.push_back(c2);
	active_ptrs.push_back(c1);
	active_ptrs.push_back(c2);
}

Model::~Model()
{
	// delete object_ptrs;
	list<GameObject *>::iterator i;
	for (i = object_ptrs.begin(); i != object_ptrs.end(); ++i)
	{
		delete *i;
	}
	cout << "Model destructed." << endl;
}

Fish *Model::get_Fish_ptr(int id_num)
{
	// use list iterator instead of this
	// push_back to add
	list<Fish *>::iterator i;
	for (i = fish_ptrs.begin(); i != fish_ptrs.end(); ++i)
	{
		if (id_num == (*i)->get_id())
			return *i;
	}
	return NULL;
}

int Model::get_time()
{
	// return 0;
	return time;
}

CoralReef *Model::get_CoralReef_ptr(int id_num)
{
	list<CoralReef *>::iterator i;
	for (i = reef_ptrs.begin(); i != reef_ptrs.end(); ++i)
	{
		if (id_num == (*i)->get_id())
			return *i;
	}
	return NULL;
}

Cave *Model::get_Cave_ptr(int id_num)
{
	list<Cave *>::iterator i;
	for (i = cave_ptrs.begin(); i != cave_ptrs.end(); ++i)
	{
		if (id_num == (*i)->get_id())
			return *i;
	}
	return NULL;
}

bool Model::update()
{
	bool b = false;
	time++;
	list<GameObject *>::iterator i;
	for (i = active_ptrs.begin(); i != active_ptrs.end(); ++i)
	{
		if ((*i)->update() == true)
			b = true;
	}
	return b;
}

void Model::show_status()
{

	cout << "---Fish---" << endl;
	list<Fish *>::iterator i;
	for (i = fish_ptrs.begin(); i != fish_ptrs.end(); ++i)
	{

		(*i)->show_status();
	}
	cout << "---Cave---" << endl;
	list<Cave *>::iterator j;
	for (j = cave_ptrs.begin(); j != cave_ptrs.end(); ++j)
	{

		(*j)->show_status();
	}

	cout << "---Reef--" << endl;
	list<CoralReef *>::iterator k;
	for (k = reef_ptrs.begin(); k != reef_ptrs.end(); ++k)
	{

		(*k)->show_status();
	}
}

void Model::display(View &view)
{
	cout << "Time: " << time << endl;
	view.clear();
	list<GameObject *>::iterator i;
	for (i = active_ptrs.begin(); i != active_ptrs.end(); ++i)
	{
		if ((*i)->is_alive())
			view.plot((*i));
	}

	view.draw();
}

Tuna *Model::find_mate(Tuna *horney_dude)
{ // find mate for horney_dude
	list<Fish *>::iterator i;
	for (i = fish_ptrs.begin(); i != fish_ptrs.end(); ++i)
	{
		if (Tuna *date = dynamic_cast<Tuna *>((*i)))
		{

			if ((horney_dude->get_cave()->get_id() == date->get_cave()->get_id()) && (horney_dude->get_id() != date->get_id()))
			{

				if (horney_dude->get_cave()->get_space() >= 10)
				{

					return (date);
				}
			}
		}
		else
			return NULL;
	}
}

void Model::create_tuna(Cave *home, Model *world)
{
	list<Fish *>::iterator i;
	for (i = fish_ptrs.begin(); i != fish_ptrs.end(); ++i)
	{
		if ((*i)->get_id() == baby_tuna)
		{
			if (Tuna *date = dynamic_cast<Tuna *>((*i)))
			{
				baby_tuna++;
			}
		}

		else
		{
			Tuna *t = new Tuna(baby_tuna, home, this);
			// baby_tuna++;
			// if (baby_tuna > 9){
			// baby_tuna = 1;
			//}
			object_ptrs.push_back(t);
			active_ptrs.push_back(t);
			fish_ptrs.push_back(t);
			cout << "Tuna " << baby_tuna << " was born in Cave " << home->get_id() << endl;
			baby_tuna++;
			if (baby_tuna > 9)
			{
				baby_tuna = 1;
			}
			break;
		}
	}
}

void Model::add_pointer(GameObject *ptr)
{
	char code = ptr->get_code();
	object_ptrs.push_back(ptr);
	active_ptrs.push_back(ptr);

	switch (code)
	{
	case 'R':
		reef_ptrs.push_back(dynamic_cast<CoralReef *>(ptr));
		cout << "Created a new Reef with id " << ptr->get_id() << " at " << ptr->get_location() << endl;
		break;
	case 'C':
		cave_ptrs.push_back(dynamic_cast<Cave *>(ptr));
		cout << "Created a new Cave with id " << ptr->get_id() << " at " << ptr->get_location() << endl;
		break;
	case 'T':
		fish_ptrs.push_back(dynamic_cast<Tuna *>(ptr));
		cout << "Created a new Tuna with id " << ptr->get_id() << " at " << ptr->get_location() << endl;
		break;
	case 'S':
		fish_ptrs.push_back(dynamic_cast<Shark *>(ptr));
		cout << "Created a new Shark with id " << ptr->get_id() << " at " << ptr->get_location() << endl;
		break;
	}
}

void Model::remove_pointer(GameObject *ptr, int id)
{
	// iterate and compare
	int in_id = ptr->get_id();
	char code = ptr->get_code();

	list<GameObject *>::iterator i;
	for (i = object_ptrs.begin(); i != object_ptrs.end(); ++i)
	{
		if ((*i)->get_id() == ptr->get_id())
		{

			switch (code)
			{
			case 'R':
				reef_ptrs.remove(dynamic_cast<CoralReef *>(ptr));
				active_ptrs.remove(ptr);
				break;
			case 'C':
				cave_ptrs.remove(dynamic_cast<Cave *>(ptr));
				active_ptrs.remove(ptr);
				break;
			case 'T':
				fish_ptrs.remove(dynamic_cast<Tuna *>(ptr));
				active_ptrs.remove(ptr);
				break;
			case 'S':
				fish_ptrs.remove(dynamic_cast<Shark *>(ptr));
				active_ptrs.remove(ptr);
				break;
			}
		}
	}
	cout << "Model: Dead object removed" << endl;
}

/*
GameObject * Model::unhidden_pointer(){

	list<Fish*>::iterator  i;
	for (i = fish_ptrs.begin(); i != fish_ptrs.end(); ++i){
		if (((*i)->get_state() != 'h') || ((*i)->get_state() == 'x')){
			return (*i);
		}
	}

	return NULL;
}
*/

std::list<Fish *> Model::unhidden_pointer()
{
	std::list<Fish *> l;
	list<Fish *>::iterator i;
	for (i = fish_ptrs.begin(); i != fish_ptrs.end(); ++i)
	{
		if (((*i)->get_state() != 'h') || ((*i)->get_state() == 'x'))
		{
			l.push_back((*i));
		}
	}

	return l;
}

Sharknado *Model::get_sharknado_ptr()
{
	// Sharknado* sharknado = new Sharknado(0, 'B', this);
	// return sharknado;
	list<Sharknado *>::iterator i;
	for (i = sharknado_ptrs.begin(); i != sharknado_ptrs.end(); ++i)
	{
		// if ('B' == (*i)->get_code())
		return (*i);
	}
	return NULL;
}

/*
void Model::save(std::ofstream &file){


	//open stream
	ofstream output;

	// Create a file
	file.open("hey.txt");

	file << get_time() << endl;
		list<GameObject*>::iterator  i;
		for (i = active_ptrs.begin(); i != active_ptrs.end(); ++i){
			// Write data

			if ((*i)->is_alive()){
				file << (*i)->get_code() << (*i)->get_id() << endl;

			}
		}

		//close stream
		file.close();
	}
	*/