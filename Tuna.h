#ifndef Tuna_H
#define Tuna_H




#include "Fish.h"


class Fish;
class Model;
class Cave;



class Tuna : public Fish{
private:


	Tuna* mate;

	double size;

	bool initiator;

	double prefeast_size;

	CartPoint destination;

	CartVector delta;

	CoralReef* reef;

	Cave* home;

	bool update_location();

	void setup_destination(CartPoint dest);

protected:
	//char display_code;/////////////////////////////you just changed this and state changing worked
	//char state;

public:

	double energy;//was provate
	Tuna();

	Tuna(int in_id, Cave* home, Model*world);

	//~Tuna();

	int time;

	//double get_size();

	bool update();

	void start_hiding(Cave* destCave);

	double get_speed();

	void show_status();

	void start_swimming(CartPoint dest);

	void start_eating(CoralReef *destReef);

	void float_in_place();

	bool is_hidden();

	bool start_mating(Tuna *fish_mate);

	void do_mating();

	//void save(std::ofstream& file);
};
#endif