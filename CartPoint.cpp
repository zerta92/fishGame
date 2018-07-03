#include <iostream>
#include <cmath>
#include "CartPoint.h"


using namespace std;

CartPoint::CartPoint()
{
	this->x = 0;
	this->y = 0;
}

CartPoint::CartPoint(double in_x, double in_y)
{
	this->x = in_x;
	this->y = in_y;
}




double cart_distance(CartPoint p1, CartPoint p2)
{
	double distance = (pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));

	return sqrt(distance);

}

////OPERATORS
CartPoint operator + (CartPoint p1, CartVector v1)
{
	double x = p1.x + v1.x;
	double y = p1.y + v1.y;
	return  CartPoint(x, y);
}

/////check if correct way (CartVector instead of CartPoint)
CartVector operator - (CartPoint p1, CartPoint p2)
{
	double x = p1.x - p2.x;
	double y = p1.y - p2.y;
	CartVector v1(x, y);


	return v1;
}

ostream & operator << (ostream& out, const CartPoint& p1)
{
	out << "(" << p1.x << "," << p1.y << ")";
	return out;
}


