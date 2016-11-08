#include <iostream>
#include "Town_Hall.h"
#include "Cart_Point.h"

// CONSTRUCTOR: DEFAULT
Town_Hall::Town_Hall() : Game_Object('t', 0, Cart_Point())
{
	this-> state = 'o';
	this-> amount = 0;
}

// CONSTRUCTOR: INPUT BASED
Town_Hall::Town_Hall(int inputId, Cart_Point inputLoc) : Game_Object('t', inputId, inputLoc)
{
	this-> state = 'o';
	this-> amount = 0;
}

// DISTRUCTOR
Town_Hall::~Town_Hall()
{
	std::cout << "Town_Hall destructed." << std::endl;
}

// PUBLIC MEMBER FUNCTION
void Town_Hall::deposit_gold(double deposit_amount)
{
	this-> amount += deposit_amount;
}

// PURELY VIRTUAL PUBLIC MEMBER FUNCTION
bool Town_Hall::update()
{
	// state would have been changed last time if it had been called before, so we check with state as well as amount
	if ( (this-> amount >= 50) && (this-> state != 'u') )
	{
		this-> state = 'u'; // u for upgraded
		this-> display_code = 'T'; // display T instead of t on map to show upgrade
		std::cout << "Town_Hall " << this-> get_id() << " has been upgraded." << std::endl;
		return true;
	}
	else return false;
}

// VIRTUAL PUBLIC MEMBER FUNCTION
void Town_Hall::show_status()
{
	// shows town hall status as: "Town hall status: T1 at location (1,20) Contains 100."
	std::cout << "Town Hall status: ";
	Game_Object::show_status();
	std::cout << " Contains " << this-> amount << std::endl;
}