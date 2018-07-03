#include <iostream>
//#include <cmath>
#include "Cave.h"
#include "Fish.h"


using namespace std;
static int caves = 1;
bool check_cave = false;//Condition so that update() returns true only once.

Cave::Cave() :GameObject(99, caves){
	//this->display_code = 99;//c
	this->state = 101;//e
	this->space = 100;
	caves++;
	cout << "Cave default constructed" << endl;


}

Cave::Cave(int in_id, CartPoint in_loc) :GameObject(99, in_id, in_loc){
	//this->display_code = 99;//c
	this->state = 101;//e
	this->space = 100;
	this->location = in_loc;
	this->id_num = in_id;
	cout << "Cave constructed" << endl;
}



bool Cave::hide_fish(Fish *fish_to_hide){

	if (!fish_to_hide->is_hidden()){//if not hidden, hide it
		double size = fish_to_hide->get_size();//original position
		if ((space >= size) == true){

			space = space - size;

			return true;
		}
	}

	
	return false;

}


bool Cave::release_fish(Fish *fish_to_hide){
	double size = fish_to_hide->get_size();
	if (fish_to_hide->is_hidden()){
		space = space + size;
		return true;
	}
	else
	{
		return false;
	}

}



bool Cave::update(){
	while (!check_cave){
		if (((space == 0) && (state != 112)) == true){
			state = 112;//p
			GameObject::display_code = 67;//C
			cout << "Cave " << get_id() << " is packed like sardines" << endl;
			check_cave = true;
			return true;//return true only when status changes to packed
		}


		if (((space == 0) && (state == 112)) == true){
			GameObject::display_code = 67;//C
			cout << "Cave " << get_id() << " is packed like sardines!" << endl;
			return false;
		}

		if (space > 0){
			//GameObject::display_code = 'C';
			return false;
		}
	}

	return false;

}



void Cave::show_status(){
	
	//CoralReef Status: R with ID 1 at location (1, 20) containing food 100
	//cout << "Cave Status: " << display_code << " with ID " << get_id() << " at location " << get_location() << "containing space " << space << endl;
	cout << "Cave Status: ";
	GameObject::show_status();
	cout << " containing space " << space << endl;
}

double Cave::get_space(){
	return space;
}


