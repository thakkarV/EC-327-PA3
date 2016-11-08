// Class Person definitions
// defines the data and behavior a peron object, a child of a game object
#include <iostream>
#include "Person.h"
#include "Game_Object.h"


// CONSTRUCTOR: DEFAULT
Person::Person();

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
	this-> state = 'm';
	std::cout <<  "Moving " << this-> get_id() << " to " << this-> destination << std::endl;
	std::cout << this-> display_code << this-> get_id() << ": On my way." << std::endl;
}

// PUBLIC MEMBER FUNCTION
void Person::stop()
{
	this-> state = 's';
	std::cout << "Stopping " << this-> get_id() << "." << endl;
	std::cout << this-> display_code << this-> get_id() << ": All right." << std::endl;
}

// PUBLIC MEMBER FUNCTION
void Person::show_status()
{
	std::cout << "Miner status: ";
	Game_Object::show_status();
	std::cout << " moving at speed of " << this-> speed << " towards ";
	std::cout << this-> destination << " at each step of " << this-> delta << endl;
}

// PROTECTED MEMBER FUNCTION
bool Person::update_location()
{

}