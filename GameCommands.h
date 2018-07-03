#ifndef GAMECOMMANDS_H
#define GAMECOMMANDS_H

#include <iostream>
//#include "GameObject.h"
//#include "Fish.h"
//#include "Cave.h"
//#include "CoralReef.h"
#include "Model.h"

using namespace std;

class GameCommands {
public:
	void do_swim_command(Model &model);

	void do_go_command(Model &model);

	void do_run_command(Model &model);

	void do_eat_command(Model &model);

	void do_float_command(Model &model);

	void do_zoom_command(Model &model);

	void handle_new_command(Model&model);

	void do_attack(Model &model);

	//void GameCommands::do_save_command(Model &model);


};


#endif