#ifndef CartVector_H
#define CartVector_H

#include <iostream>
#include <cmath>
//#include "CartPoint.h"




using namespace std;

class CartVector{

public:
	double x;
	double y;

	CartVector();

	CartVector(double in_x, double in_y);



};

CartVector operator * (CartVector v1, double d);
CartVector operator / (CartVector v1, double d);
ostream & operator << (ostream& out, const CartVector& v1);//just added



#endif
