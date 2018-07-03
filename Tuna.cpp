#include <iostream>
#include "Tuna.h"
#include "CartPoint.h"
#include "Model.h"

using namespace std;
//update for inherited classes fish/shark
//show update for inherited classes

//mating (when to call and how)
//stl

//world pointer


Tuna::Tuna(int id, Cave *home, Model*world) :Fish('T', id, home, 10, world){//for sharks
	this->home = home;
	this->state = 'h';
	this->energy = 15;
	this->size = 10;
	//this->prefeast_size = this->size;
	this->destination = CartPoint();
	//this->location = home->get_location();
	this->reef = NULL;
	this->time = 0;
	this->initiator = false;

	//cout << "Tuna constructed" << endl;


}
//10
Tuna::Tuna() :Fish('T', 10, world){

	this->state = 'h';
	this->energy = 15;
	this->time = 0;
	this->size = 10;
	//this->prefeast_size = this->size;
	this->destination = CartPoint();//NULL
	//this->location = home->get_location();
	this->reef = NULL;
	this->home = NULL;
	this->initiator = false;

	//cout << "Tuna default constructed" << endl;


}

double Tuna::get_speed(){
	double speed;
	speed = (1 / (Fish::get_size()))*(energy)* 4;

	return speed;
}

void Tuna::do_mating(){
	cout << get_code() << get_id() << ": I found my mate!" << endl;
	state = 'm';


}


static int tunas = 4;
bool Tuna::update(){
	//cout << "state for" << get_id() << "is: " << state << endl;
	Fish::update();
	switch (state){
	case 'm':
		time++;
		if ((initiator == true) && (time == 2)){
			//cout << get_code() << get_id() << ": About to make a fucking baby tuna" << endl;
			//time = 0;
			//mate->time = 0;
			//cout << "changing states back to h" << endl;
			this->state = 'h';
			mate->state = 'h';
			cout << "state is " << state << endl;
			cout << "mate state is " << mate->state << endl;
			//initiator = false;
			world->create_tuna(home, world);

		}
		return false;

	case 'h':
		Tuna* lucky_mate = world->find_mate(this);
		if (lucky_mate != NULL){
			//if (lucky_mate->initiator == false){//new line
			if (start_mating(lucky_mate));
			return true;

			}
		//}//new line
		else
			return false;
	}

}




bool Tuna::start_mating(Tuna *fish_mate){
	int tick_count = time;
	mate = fish_mate;
	if ((Fish::get_size() >= 40 && Fish::get_size() <= 60) && (fish_mate->Fish::get_size() >= 40 && fish_mate->Fish::get_size() <= 60) && (state == 'h') && (fish_mate->state == 'h')){///check fourth condition
		initiator = true;//if this is already true dont run start mating
		this->do_mating();
		fish_mate->do_mating();
		return true;
	}
	
	return false;


}


void Tuna::show_status(){
	cout << "Tuna status: ";
	Fish::show_status();
	if (state == 'm')
		cout << get_code() << " with ID " << this->get_id() << " at location " << get_location() << " is mating in Cave " << home->get_id() << endl;
	else
		return;


}



