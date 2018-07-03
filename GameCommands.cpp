#include <iostream>
#include "GameCommands.h"
#include "InputHandling.h"
#include <stdlib.h> 
//#include "Sharknado.h"//////////
using namespace std;



void GameCommands::do_swim_command(Model &model){
	int id_num;
	double x;
	double y;
	//cin >> id_num >> x >> y;
	if (!(cin >> id_num)){
		throw InvalidInput("Was expecting an int");
	}

	if (!(cin >> x)){
		throw InvalidInput("Was expecting  a double");
	}

	if (!(cin >> y)){
		throw InvalidInput("Was expecting  a double");
	}

	
		Fish *f = model.get_Fish_ptr(id_num);
		if (f == (Fish*)NULL) // check: is ID valid?
			throw InvalidInput("Invalid Fish ID");
		f->start_swimming(CartPoint(x, y));
	
}

void GameCommands::do_eat_command(Model &model){
	int id_num;
	int id_num_cr;
	if (!(cin >> id_num))
		throw InvalidInput("Was expecting an integer for fish id");

	if (!(cin >> id_num_cr))
		throw InvalidInput("Was expecting an integer for fish id");
	//cin >> id_num >> id_num_cr;
	Fish *f = model.get_Fish_ptr(id_num);
	if (f == (Fish*)NULL) // check: is ID valid?
		throw InvalidInput("Invalid Fish ID");
	CoralReef *cr = model.get_CoralReef_ptr(id_num_cr);
	if (cr == (CoralReef*)NULL) // check: is ID valid?
		throw InvalidInput("Invalid Reef ID");
	f->start_eating(cr);//check
}

void GameCommands::do_float_command(Model &model){
	int id_num;
	if (!(cin >> id_num))
		throw InvalidInput("Was expecting an integer for fish id");
	
	Fish *f = model.get_Fish_ptr(id_num);
		if (f == (Fish*)NULL) // check: is ID valid?
			throw InvalidInput("Invalid Fish ID");


	
	f->float_in_place();
}

void GameCommands::do_zoom_command(Model &model){
	int id_num;
	int id_num_c;

	if (!(cin >> id_num))
		throw InvalidInput("Was expecting an integer for fish id");

	if (!(cin >> id_num_c))
		throw InvalidInput("Was expecting an integer for cave id");

	Fish *f = model.get_Fish_ptr(id_num);
	if (f == (Fish*)NULL) // check: is ID valid?
		throw InvalidInput("Invalid Fish ID");

	Cave *c = model.get_Cave_ptr(id_num_c);
	if (c == (Cave*)NULL) // check: is ID valid?
		throw InvalidInput("Invalid Cave ID");
	f->start_hiding(c);//check
}

void GameCommands::do_go_command(Model &model){

	
	model.update();
	model.get_sharknado_ptr()->wipe();

}
/*
void GameCommands::do_run_command(Model &model){
	int count = 0;
	bool b = model.update();
	
	model.get_sharknado_ptr()->wipe();
	model.get_sharknado_ptr()->wipe();
	while (((!b) && (count < 4))){
		
		count++;
		b = model.update();
		model.get_sharknado_ptr()->wipe();
		
	} 
	
}
*/

void GameCommands::do_run_command(Model &model){
	int count = 0;

	while (count < 4){
		if (model.update()) {
			break;
		}
		count++;
		model.get_sharknado_ptr()->wipe();

	}

}



void GameCommands::do_attack(Model &model){
	int id_num_attacker;
	int id_num_victim;

	if (!(cin >> id_num_attacker))
		throw InvalidInput("Was expecting an integer for attacker id");

	if (!(cin >> id_num_victim))
		throw InvalidInput("Was expecting an integer for victim id");

	//cin >> id_num_attacker >> id_num_victim;
	Fish *f1 = model.get_Fish_ptr(id_num_attacker);
	if (f1 == (Fish*)NULL) // check: is ID valid?
		throw InvalidInput("Invalid Predator Fish ID");
	Fish *f2 = model.get_Fish_ptr(id_num_victim);
	if (f2 == (Fish*)NULL) // check: is ID valid?
		throw InvalidInput("Invalid Fish ID");

	f1->start_attack(f2);
}


void GameCommands::handle_new_command(Model& model){
	char type;
	int id;
	double x;
	double y;
	int cave_id;
	cin >> type;

	switch (type){
	case 'r':{
	cin >> id >> x >> y;
	CoralReef *r = new CoralReef(id, CartPoint(x, y));
	model.add_pointer(r);
	break;
	}
	case 'c':{
		cin >> id >> x >> y;
		Cave *c = new Cave(id, CartPoint(x, y));
		model.add_pointer(c);
		break;
	}
	case 't':
	{

		cin >> id >> cave_id;
		Cave *new_home = model.get_Cave_ptr(cave_id);
		Tuna* t = new Tuna(id, new_home, &model);
		model.add_pointer(t);
		break;
	}
	case 's':
	{

		cin >> id;
		int time = model.get_time();
		srand(time);
		double x = rand() % 21;
		double y = rand() % 21;
		Shark* s = new Shark(id, CartPoint(x,y) ,&model);
		model.add_pointer(s);
		break;
	}

	}


}

/*
void GameCommands::do_save_command(Model &model){
	ofstream filename;
	//if (!(cin >> filename))
		//throw InvalidInput("invalid filename");

	model.save(filename);
	
}
*/