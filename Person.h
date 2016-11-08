#ifndef PERSON_H
#define PERSON_H

#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"

class Person : public Game_Object
{
public: 
	Person();

	Person(char in_code);
	// input based constructor also initialises speed
	// Outputs a message "Person default constructed."

	Person(char in_code, int in_id, Cart_Point in_loc);
	// input based constructor that initialises code, id and location
	// Also sets speed and outputs a message screen "Person constructed."

	void start_moving(Cart_Point dest);
	// sets the person in motion towards the destination point by calling another function setup_destination()
	// changes state to 'm' for moving and prints "Moving (id) to (destination)."
	// and another message "(display_code)(id): On my way."

	void stop();
	// stops the movement of the person and sets state to 's' for stopped
	// Prints "Stopping (id)." and another message "(display_code)(id): All right."

	void show_status();
	// It first calls Game_Object::show_status(), and then outputs the information
	// contained in this class for the moving state and the stopped state: speed, destination, delta

	
	/* NOTE:
	 |	get_location is defined in Game_Object.cpp
	 |  get_id is defined in Game_Objectc.pp
	 */

protected:
	bool update_location();
	// Updates the object's location while it is moving
	// Prints "(display_code)(id): I’m there!" if Miner has arrived to destination.
	// Prints "(display_code)(id): step…" otherwise.

	void setup_destination(Cart_Point dest);
	// Sets up the object to start moving to destination location

private:
	double speed;
	// The speed this object travels, expressed as distance per update time unit, Initial value 5.

	Cart_Point destination;
	// the destination location coordiate to which the person is headed

	Cart_Vector delta;
	// Contains the x and y amounts that the object will move on each time unit

};

#endif