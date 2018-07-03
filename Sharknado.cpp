#include "Sharknado.h"

Sharknado::Sharknado(int id, char code, Model * world): GameObject(id, code) {
	this->timer_of_doom = world->get_time();
	this->world = world;
}


int p = 0;
void Sharknado::wipe(){
	this->timer_of_doom = world->get_time();
	//for (int i = 0; i < 4; ++i){
		//GameObject* x = world->unhidden_pointer(); works
		std::list<Fish*> test =  world->unhidden_pointer();
		test.unique();
		//cout << x->get_code() << x->get_id() << endl;
		//dead_ptrs.push_back(dynamic_cast<Fish*>(x)); works
		//dead_ptrs.unique(); works
	//}
	

	///////////
	//list<Fish*>::iterator  j;
	//for (j = dead_ptrs.begin(); j != dead_ptrs.end(); ++j){
	//	cout << (*j)->get_code() << (*j)->get_id() << endl;
	//}

	////////

	
	if ((timer_of_doom % (10+(15*p)) == 0)&& (timer_of_doom > 0)){
		cout << "The Sharknado is coming!" << endl;
	}

	if ((timer_of_doom % 15 == 0) && (timer_of_doom > 0)){
		cout << "The Sharknado is upon us!" << endl;
		list<Fish*>::iterator  i;
		for (i = test.begin(); i != test.end(); ++i){
			if (((*i)->get_state() != 'h') || ((*i)->get_state() == 'x'))
			world->remove_pointer((*i), (*i)->get_id());
			dead_ptrs.push_back((*i));
		}

		p = p + 1;
		cout << "---------The Sharknado Claimed---------" << endl;
		int number = 1;
		list<Fish*>::iterator  j;
		for (j = dead_ptrs.begin(); j != dead_ptrs.end(); ++j){
			cout<<"(" <<number<<")"<<" - " <<(*j)->get_code() << (*j)->get_id() << endl;
			++number;
		}
		number = 0;
		cout << "---------------------------------------" << endl;
		dead_ptrs.clear();

	}
}

bool Sharknado::update(){
	if (timer_of_doom % 10 == 0){
		cout << "Sharknado Warning" << endl;
	}
	return false;
}


