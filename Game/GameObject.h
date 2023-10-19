#ifndef GameObject_H
#define GameObject_H
#include <iostream>
#include <cmath>
#include "../Coordinates/CartVector.h"
#include "../Coordinates/CartPoint.h"

using namespace std;

class GameObject
{

private:
protected:
	CartPoint location;

	int id_num; ////was private

	char display_code;

	char state;

public:
	GameObject(char in_code, int in_id);

	GameObject(char in_code, int in_id, CartPoint in_loc);

	void drawself(char *grid); ////////////////////

	CartPoint get_location();

	int get_id();

	virtual void show_status();

	virtual bool update() = 0; // purely virtual function

	char get_code();

	virtual bool is_alive();

	// virtual void save(ofstream& file);
};

#endif
