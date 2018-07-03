#include <iostream>
#include <cmath>
#include "GameObject.h"
//#include <fstream>



using namespace std;

GameObject::GameObject(char in_code, int in_id){
	this->display_code = in_code;
	this->id_num = in_id;
	//this->location = CartPoint();//check if 0,0
	cout << "Game Object  Constructed" << endl;

}

GameObject::GameObject(char in_code, int in_id, CartPoint in_loc){
	this->display_code = in_code;
	this->id_num = in_id;
	this->location = in_loc;
	cout << "Game Object Constructed" << endl;
}


int GameObject::get_id(){

	return id_num;
}



CartPoint GameObject::get_location(){
	return location;
}


void GameObject::show_status(){
	cout << display_code << " with ID " << id_num << " at location " << get_location();
}

void GameObject::drawself(char* grid){

	grid[0] = display_code;
	grid[1] = get_id();

}

char GameObject::get_code(){
	return display_code;
}

bool GameObject::is_alive(){

	if (state != 'x')
		return true;
	if (state == 'x')
		return false;

}

