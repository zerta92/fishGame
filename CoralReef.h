#ifndef CoralReef_H
#define CoralReef_H

#include <iostream>
//#include <cmath>
//#include "CartVector.h"
//#include "CartPoint.h"
#include "GameObject.h"


using namespace std;

class CoralReef : public GameObject
{

private:
	double amount;//food

protected:
	char display_code;
	char state;

public:


	bool is_empty();

	double provide_food(double amount_to_provide = 20.0);

	bool update();

	void show_status();

	CoralReef();

	CoralReef(int in_id, CartPoint in_loc);


	//void save(std::ofstream& file);

	

};




#endif
