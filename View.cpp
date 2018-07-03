
#include "View.h"


using namespace std;


View::View(){
	this->size = 11;
	this->scale = 2;
	this->origin = CartPoint();//(0,0)

}

bool View::get_subscripts(int &ix, int &iy, CartPoint location){
	CartVector subscript = location - origin;
	subscript = subscript / scale;
	iy = subscript.y;
	ix = subscript.x;

	if (ix <= size && iy <= size){
		return true;
	}
	else{
		cout << "an object is outside the display " << endl;
		return false;
	}

}

void View::clear(){
	for (int i = 0; i <size; i++){

		for (int j = 0; j < size; j++){
			grid[i][j][0] = '.';
			grid[i][j][1] = ' ';
		}
	}
}

void View::plot(GameObject *ptr)
{
	CartPoint temp_loc = ptr->get_location();
	int	ix = temp_loc.x;
	int iy = temp_loc.y;

	if (get_subscripts(ix, iy, ptr->get_location())){

		if (grid[10 - iy][ix][0] == '.'){
			ptr->drawself(grid[10 - iy][ix]);
		}

		else{
			ptr->drawself(grid[10 - iy][ix]);
			grid[10 - iy][ix][0] = '*';
			grid[10 - iy][ix][1] = ' ';
		}

	}

}

void View::draw()
{
	
	for (int i = 0; i <size; i++)
	{
		if (i == 0 || i % 2 == 0){
			cout << 20 - (2 * i) << "   ";
		}
		else{
			cout << "  " << "   ";
		}

		for (int j = 0; j<size; j++){

			cout << grid[i][j][0];
			cout << grid[i][j][1];
		}

		cout << endl;
	}

	for (int k = 0; k <size; k++){
		if (k == 0 || k % 2 == 0){
			if (k >= 5)
				cout << 2 * k << "  ";
			else
				cout << 2 * k << "   ";
		}

	}

	cout << endl;

}