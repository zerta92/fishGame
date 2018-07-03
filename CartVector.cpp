#include <iostream>
#include <cmath>
#include "CartVector.h"
//#include "CartPoint.h"
//#include "GameObject.h"

using namespace std;

CartVector::CartVector()
{
	this->x = 0;
	this->y = 0;
}


CartVector::CartVector(double in_x, double in_y)
{
	this->x = in_x;
	this->y = in_y;
}


CartVector operator * (CartVector v1, double d)
{
	//double x = v1.x * d;
	//double y = v1.y * d;
	return  CartVector(v1.x * d, v1.y * d);
}

CartVector operator / (CartVector v1, double d)
{
	//double x = v1.x / d;
	//double y = v1.y / d;
	return  CartVector(v1.x / d, v1.y / d);
}

ostream & operator << (ostream& out, const CartVector& v1){//just added
	out << "<" << v1.x << "," << v1.y << ">";
	return out;
}