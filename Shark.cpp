#include <iostream>
#include "Shark.h"
#include "CartPoint.h"
//#include <cstdlib>
#include "Model.h"
#include <stdlib.h>
using namespace std;


static int sharks = 0;
/*Model* world;
CartPoint rand_point(){
//seed with model time
srand(world->get_time());
int x = rand() % 21;
int y = rand() % 21;
return CartPoint(x, y);
}
*/

Shark::Shark(int id, Model* world) :Fish('S', id, CartPoint(0,0) ,20, world){
	this->state = 'f';
	this->range = 1;
	this->energy = 15;
	this->size = 20;
	this->location = CartPoint();
	this->attack_strength = 2;


	//cout << "Shark default constructed" << endl;

}

Shark::Shark(int in_id, CartPoint rand_point, Model*world) :Fish('S', in_id, rand_point, 20, world){
	this->state = 'f';
	this->energy = 15;
	this->size = 20;
	this->location = rand_point;
	this->attack_strength = 2;
	this->range = 1;
	//cout << "Shark constructed" << endl;

}

double Shark::get_speed(){
	double speed;
	speed = (1 / (size))*(energy)* 8;

	return speed;
}

void Shark::start_attack(Fish* target){
	if (this->is_alive()){
		if (target->is_alive()){
			if (fabs(cart_distance(target->get_location(), location)) <= range){
				cout << "Chomp!" << endl;
				state = 'a';
				this->target = target;
				target->get_bitten(attack_strength);

			}
			else{
				cout << "Fish are friends, not food" << endl;
			}
		}
	}
	else{
		cout << "This Fish is dead" << endl;
	}
}

bool Shark::update(){
	switch (state)
	{
	case 'x':
		return false;
	case 's':
		return false;
	case 'e':
		Fish::update();


	case 'a':
		if (cart_distance(get_location(), target->get_location()) > range){

			cout << get_code() << get_id() << ":Darn! It escaped. " << endl;
			target = NULL;
			state = 'f';
			return true;
		}

		if (cart_distance(get_location(), target->get_location()) <= range){

			if (target->is_alive()){
				state = 'a';
				cout <<get_code()<<get_id() <<": Chomp!" << endl;
				target->get_bitten(attack_strength);
				return false;
			}

			if (!target->is_alive()){
				cout << get_code() << get_id()<< ": I triumph!" << endl;
				state = 'f';
				energy = energy + 5;
				return true;
			}

		}

	}
}
void Shark::show_status(){
	cout << "Shark status: ";
	Fish::show_status();
	if (state == 'a')
		cout <<get_code()<< " with ID " << Fish::get_id()<<" at location "<< get_location()<<" is attacking Fish "<<target->get_id()<< endl;
	else
		return;
}

// chapter 15 
//Shark* s = dynamic_cast<Shark*>(s);