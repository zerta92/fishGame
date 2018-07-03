#include <iostream>

#include "Fish.h"
//#include "Tuna.h"

#include "CartPoint.h"
#include "Model.h"

using namespace std;



Fish::Fish(char display_code, int size, Model *world) :GameObject(display_code, 0){
	this->home = NULL;
	//this->energy = 15;
	this->size = size;
	//this->state = 'h';
	this->prefeast_size = this->size;
	this->location = home->get_location();
	//this->destination = NULL;
	this->reef = NULL;
	this->world = world;
	cout << "Fish default constructed" << endl;


}

Fish::Fish(char display_code, int in_id, Cave* home, int size, Model* world) :GameObject(display_code, in_id, home->get_location()){
	this->home = home;
	this->size = size;//e
	home->hide_fish(this);
	this->world = world;
	//this->state = 'h';
	this->energy = 15;
	this->prefeast_size = this->size;
	//this->location = home->get_location();
	//this->destination = CartPoint();
	this->reef = NULL;

	cout << "Fish constructed" << endl;
}


Fish::Fish(char display_code, int in_id, CartPoint p1, int size, Model* world) :GameObject(display_code, in_id){
	//this->home = NULL;
	this->energy = 15;
	this->size = size;
	//this->state = 'h';//////////////////////
	this->prefeast_size = this->size;
	//this->location = p1;
	this->reef = NULL;
	this->world = world;

	cout << "Fish default constructed" << endl;


}

Fish::~Fish(){

	cout << "Fish destructed." << endl;


}

char Fish::get_display(){
	return display_code;
	
}



bool Fish::update_location(){
	
		if (((fabs(destination.x - location.x) <= fabs(delta.x)) && (fabs(destination.y - location.y) <= fabs(delta.y))) == true){
			GameObject::location = destination;
			cout << GameObject::display_code << get_id() << ": Im There" << endl;
			/////////////////////////////////

			while (reef != NULL){
				CartPoint reef_location = reef->get_location();
				if ((location.x == reef_location.x) && (location.y == reef_location.y)){
					cout << GameObject::display_code << get_id() << ": Starting to dine at a coral reef" << endl;
					break;
				}
				return true;
			}

			////////////////////////////////////
			return true;
		}
		else {
			this->location = GameObject::location + delta;//increase a step
			cout << GameObject::display_code << get_id() << ": Just Keep Swimming" << endl;
			return false;
		}
		return false;

}


void Fish::setup_destination(CartPoint dest){
	double distance = cart_distance(dest, location);
	this->destination = dest;
	this->delta = (dest - get_location())*(get_speed() / distance);
	if (distance == 0){
		delta = CartVector(0, 0);
	}
	
}

double Fish::get_size(){
	return size;
}

char Fish::get_state(){
	return state;
}

/*double Fish::get_speed(){
double speed;
speed = (1 / (size))*(energy)* 5;
return speed;
}
*/

void Fish::show_status(){
	

	if (state == 'f'){//f floating
		//cout << "Fish Status: ";
		GameObject::show_status();
		cout << " is floating, Has a size of: " << get_size() << " and energy of " << energy << endl;
	}


	if (state == 's'){//s swimming
		//cout << "Fish Status: ";
		GameObject::show_status();
		cout << "  has a speed of: " << get_speed() << " and is heading to " << destination << endl;
	}

	if (state == 'o'){//o outbound swimming to eat
		//cout << "Fish Status: ";
		GameObject::show_status();
		cout << "  is outbound to reef " << reef->get_id() << " with a speed of " << get_speed() << endl;
	}


	if (state == 'e'){//e eating
		//cout << "Fish Status: ";
		GameObject::show_status();
		cout << " is eating at reef " << reef->get_id() << endl;
	}

	if (state == 'z'){//z zooming
		//cout << "Fish Status: ";
		GameObject::show_status();
		cout << " is swimming to cave " << home->get_id() << " with a speed of " << get_speed() << endl;
	}


	if (state == 'h'){//h hidding
		//cout << "Fish Status: ";
		GameObject::show_status();
		cout << " Is hidden at cave " << home->get_id() << endl;
	}

	if (state == 'p'){//p panicked
		//cout << "Fish Status: ";
		GameObject::show_status();
		cout << " Is panicked and has a size of " << get_size() << endl;
	}

	if (state == 'x'){//p panicked
		//cout << "Fish Status: ";
		GameObject::show_status();
		cout << " is dead " << endl;
	}

}

void Fish::start_swimming(CartPoint dest){
	if (this->is_alive()){
		home->release_fish(this);
		setup_destination(dest);
		state = 's';
		cout << "Swimming " << get_id() << " to " << dest << endl;
		cout << GameObject::display_code << get_id() << ": On My Way!" << endl;
	}

	else{
		cout << "This fish is dead" << endl;
	}
}

void Fish::start_eating(CoralReef *destReef){
	if (this->is_alive()){
		home->release_fish(this);
		reef = destReef;
		setup_destination(destReef->get_location());
		this->state = 'o';
		cout << "Fish " << get_id() << " eating at Coral Reef " << destReef->get_id() << " and returning back to Cave " << home->get_id() << endl;
		cout << GameObject::display_code << get_id() << ": Food here I come" << endl;
	}

	else{
		cout << "This fish is dead" << endl;
	}
}

void Fish::start_hiding(Cave* destCave){
	
	if (state == 'h'){
		home->release_fish(this);
	}
	
	home = destCave;
	setup_destination(home->get_location());
	state = 'z';
	cout << "Fish " << get_id() << " Swimming to cave " << home->get_id() << endl;
	cout << GameObject::display_code << get_id() << ": Off to safety" << endl;



}

void Fish::float_in_place(){
	if (this->is_alive()){
		state = 'f';
		cout << "Stopping " << display_code << get_id() << endl;
		cout << GameObject::display_code << get_id() << ": Resting my fins" << endl;
	}
	else{
		cout << "This fish is dead" << endl;
	}
}

bool Fish::is_hidden(){
	if (state == 'h'){
		return true;
	}
	else{
		return false;
	}
}


bool Fish::update(){
	switch (state){
	case 's'://s swimming

		if (update_location()){
			state = 'f';
			return true;

		}
		else{
			return false; //stay in swimming state

		}





	case 'h'://hidden///add new hidden state to tuna
		if (is_hidden()){
			energy = energy - (energy*.25);
			if (energy < 5){
				home->release_fish(this);
				state = 'x';
				return true;
			}
			//cout << "returning true" << endl;
			return true;///false
		}
		//else{//
			//return false;//
		//}//


	case 'x':
		return true;


	case 'o'://o outbound swimming to eat
		if (update_location()){
			prefeast_size = size;
			state = 'e';

			return true;

		}
		else{
			return false;

		}



	case 'e'://e eating
		if (reef->is_empty()){
			state = 'f';
			cout << GameObject::display_code << get_id() << ": This reef has no more food for me" << endl;
			return false;
			}

		if ((!reef->is_empty()) && (this->is_alive()) ){
			while ((this->size < (2 * this->prefeast_size)) == true){
				this->size = this->size + reef->provide_food()*(.5);
				state = 'e';
				cout << GameObject::display_code << get_id() << ": Grew to size " << size << endl;
				if (reef->is_empty()){
					state = 'f';
					cout << GameObject::display_code << get_id() << ": This reef has no more food for me" << endl;
					return false;
					}
				return false;
			}
			
				setup_destination(home->get_location());
				cout << GameObject::display_code << get_id() << ": I'm full. I'm heading home" << endl;
				state = 'z';
				return true;
			
		
		}




	case 'z'://z zooming to home

		if (update_location()){
			bool check_space = home->hide_fish(this);
			if (check_space){
				state = 'h';//h
				//h = false;//reset h since state changed
				cout << GameObject::display_code << get_id() << ":" << " Im hidden and safe" << endl;
				return true;//arrived
			}
			if (!check_space){
				state = 'p';//panick
				cout << GameObject::display_code << get_id() << ":" << " Help! My home is full" << endl;
				return true;
			}
			else{
				return false;
			}
		}






	}
	return false;
}

void Fish::start_attack(Fish*){
	cout << get_code() << get_id() << ": I am only shark Food" << endl;
}


void Fish::start_mating(Fish*){

	//cout <<get_code() <<get_id()<<": I cannot mate" << endl;

}

void Fish::get_bitten(int attack_strength){

	energy = energy - attack_strength;
	if (this->is_alive()){
		if (energy <= 0){
			cout << get_code() << get_id() << ": Oh no, Ive become chum!" << endl;
			state = 'x';
			
		}

		else{
			cout << get_code() << get_id() << ": Ouch!" << endl;
		}
	}



}

bool Fish::is_alive()
{
	if (state != 'x')
		return true;
	if (state == 'x')
		return false;

	return false;
}

Cave* Fish::get_cave(){
	return home;
}


