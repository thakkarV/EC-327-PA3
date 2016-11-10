#include <iostream>
#include <cmath> // for pow and sqrt functions
#include "Cart_Vector.h"
#include "Cart_Point.h"
// Class Cart_Point definitions
// stores the x and y cartesian coordinates of all game objects

// CONSTRUCTOR: DEFAULT
Cart_Point::Cart_Point()
{
	this-> x = 0.0;
	this-> y = 0.0;
}

// CONSTRUCTOR: INPUT BASED
Cart_Point::Cart_Point(double inputx, double inputy)
{
	this-> x = inputx;
	this-> y = inputy;
}

// NON-MEMBER FUNCTION
double cart_distance(const Cart_Point & p1, const Cart_Point & p2)
{
	double distance;
	// sum the square of the difference of each vector component
	distance = ((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y));
	return FXSQRT(distance);
}

// OPERATOR OVERLOAD
Cart_Point operator + (const Cart_Point & p1, const Cart_Vector & v1)
{
	// p1 + v1 returns a new p1 with the translation component proportional to vector direction
	double pointx = p1.x + v1.x;
	double pointy = p1.y + v1.y;
	return Cart_Point(pointx, pointy);
}

// OPERATOR OVERLOAD
Cart_Vector operator - (const Cart_Point & p1, const Cart_Point & p2)
{
	// p1 - p1 gives a Cart_Vector object that is the vector form p1 pointing to p2
	double vecx = p1.x - p2.x;
	double vecy = p1.y - p2.y;
	return Cart_Vector(vecx, vecy);
}

// OPERATOR OVERLOAD
std::ostream & operator << (std::ostream & out, const Cart_Point & p1)
{
	out << "(" << p1.x << ", " << p1.y << ")";
	return out;
}

// NON MEMBER FUNCTION: fast approximate square root
double FXSQRT(double guess)
{
	// ITS FROM QUAKE III ARENA ?!?!?!? HOLY SHIT.....
	// implementing the what the fuck algorithem with the magic hex...
	// i have no clue how this works and hoestly as this point...
	// i don't give a fyling fuck !

	double halfGuess = 0.5 * guess;
	
	// evil floating point bit level hacking
	long i = *(long *) &guess;
	i = 0x5fe6eb50c7b537a9 - (i >> 1);
	guess = *(double *) &i;

	// i cant even anymore...
	guess = guess * (1.5 - halfGuess * guess * guess);
	guess = guess * (1.5 - halfGuess * guess * guess);
	guess = guess * (1.5 - halfGuess * guess * guess);

	// lets just be done with this shit now...
	guess = 1 / guess;
	return guess;
}