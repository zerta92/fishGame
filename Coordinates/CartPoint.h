#ifndef CartPoint_H
#define CartPoint_H

#include <iostream>

#include "CartVector.h"



using namespace std;

class CartPoint{

public:
	double x;
	double y;

	CartPoint();


	CartPoint(double in_x, double in_y);





};


double cart_distance(CartPoint p1, CartPoint p2);
CartPoint operator + (CartPoint p1, CartVector v1);
CartVector operator - (CartPoint p1, CartPoint p2);
ostream & operator << (ostream& out, const CartPoint& p1);//just added






#endif
