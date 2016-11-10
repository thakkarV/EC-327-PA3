// Class Person definitions
// defines the data and behavior a peron object, a child of a game object
#include <iostream>
#include <math.h> // for fabs() function
#include "Cart_Point.h"
#include "Person.h"
#include "Game_Object.h"


// CONSTRUCTOR: DEFAULT
Person::Person() {}

// CONSTRUCTOR: INPUT BASED
Person::Person(char in_code) : Game_Object(in_code, 0)
{
	this-> speed = 5;
	std::cout << "Person default constructed." << std::endl;
}

// CONSTRUCTOR: INPUT BASED
Person::Person(char in_code, int in_id, Cart_Point in_loc) : Game_Object(in_code, in_id, in_loc)
{
	this-> speed = 5;
	std::cout << "Person constructed." << std::endl;
}

// PUBLIC MEMBER FUNCTION
void Person::start_moving(Cart_Point dest)
{
	// first setup the destination
	this-> setup_destination(dest);
	// after calling setup destination, it sets the state to moving and prints out message
	this-> state = 'm';
	std::cout << "Moving " << this-> get_id() << " to " << this-> destination << std::endl;
	std::cout << this-> display_code << this-> get_id() << ": On my way." << std::endl;
}

// PUBLIC MEMBER FUNCTION
void Person::stop()
{
	// change state and print message
	this-> state = 's';
	std::cout << "Stopping " << this-> get_id() << "." << std::endl;
	std::cout << this-> display_code << this-> get_id() << ": All right." << std::endl;
}

// PUBLIC MEMBER FUNCTION
void Person::show_status()
{
	Game_Object::show_status();
	std::cout << this-> display_code << this-> get_id() << " moving at speed of " << this-> speed 
			  << " towards " << this-> destination << " at each step of " << this-> delta << std::endl;
}

// PROTECTED MEMBER FUNCTION
bool Person::update_location()
{
	// this funciton changes the location of the person object when it is in motion
	Cart_Vector difference = this-> destination - this-> location;
	// note to self: fabs stands for floating point absolute lol
	if ( (fabs(difference.x) <= this-> location.x) && (fabs(difference.y) <= this-> location.y) )
	{
		// if within one step of destination, set current location to destination and true for reaching
		this-> location = this-> destination;
		std::cout << "I’m there!" << std::endl;
		return true;
	}
	else
	{
		// if not within one step, add the speed delta to location and return flase
		this-> location = this-> location + this-> delta;
		std::cout << "moved" << std::endl;
		return false;
	}
}

// PROTECTED MEMBER FUNCTION
void Person::setup_destination(Cart_Point dest)
{
	this-> destination = dest;
	// changes the destination Cart_Point data member of the person object

	this-> delta = ( (this-> destination - this-> location) * (speed / cart_distance(destination, location)) );
	// also caculates the delta value and changes the data member in person object
}