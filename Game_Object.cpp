#include <iostream>
#include "Game_Object.h"
#include "Cart_Point.h"

Game_Object::Game_Object() {}

Game_Object::Game_Object(char in_code, int in_id)
{
	this->display_code = in_code;
	this->id_num = in_id;
	this->location = Cart_Point();
	std::cout << "Game_Object default constructed." << std::endl;
}

Game_Object::Game_Object(char in_code, int in_id, Cart_Point in_loc)
{
	this->display_code = in_code;
	this->id_num = in_id;
	this->location = in_loc;
	std::cout << "Game_Object constructed." << std::endl;
}

// DISTRUCTOR
Game_Object::~Game_Object()
{
	std::cout << "Game_Object destructed." << std::endl;
}

Cart_Point Game_Object::get_location()
{
	return this->location;
}

// PUBLIC MEMBER FUNCTION
int Game_Object::get_id()
{
	// returns the integer id of the mine
	return this->id_num;
}

// PUBLIC MEMBER FUNCTION // virtual
void Game_Object::show_status()
{
	std::cout << this->display_code << this->get_id() << " at location " << this->location;
}