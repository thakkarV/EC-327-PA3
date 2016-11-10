// Class Miner definitions
// defines the data and behavior of a miner object, a child of a person object, a child of a game object
#include <iostream>
#include "Miner.h"
#include "Person.h"
#include "Cart_Point.h"
#include "Cart_Vector.h"
#include "Game_Object.h"
#include "Gold_Mine.h"
#include "Town_Hall.h"

// CONSTRUCTOR: DEFAULT
Miner::Miner() : Person('M')
{
	this-> amount = 0;
	this-> mine = 0; // NULL pointer
	this-> home = 0; // NULL pointer
	std::cout << "Miner default constructed." << std::endl;
}

Miner::Miner(int in_id, Cart_Point in_loc) : Person('M', in_id, in_loc)
{
	this-> amount = 0;
	this-> mine = 0; // NULL pointer
	this-> home = 0; // NULL pointer
}

bool Miner::update()
{
	// this is the function that makes the miner object a finite state automaton
	// impletemnted in the following switch statement for the state varaible
	switch (this-> state)
	{
		case 's' : // stopped
		{
			// nothing to do in this case, just show status
			this-> show_status();
			return false;
		}
		case 'm' : // moving
		{
			this-> show_status();
			// call update_location function in parent person to change location
			if (update_location())
			{
				this-> state = 's'; // if arrived, set state to stopped

				return true;
			}
			else
			{
				return false;				
			}
		}
		case 'o' : // outbound
		{
			this-> show_status();
			if (update_location())
			{
				// if the person has arrived, change state to getting gold
				this-> state = 'g';
				return true;
			}
			else
			{
				// else stay outbound
				return false;
			}
		}
		case 'g' : // getting gold
		{
			// first  dig gold and then add that to miners amount
			double duggold = this-> mine-> dig_gold();
			this-> amount += duggold;
			std::cout << display_code << Game_Object::get_id() << ": Got " << duggold << " gold." << std::endl;

 			// now setup_destination to move towards the town hall
 			Person::setup_destination(this-> home-> get_location());
 			// and now change state to inbound
 			this-> state = 'i';
 			return true;
		}
		case 'i' : // inbound
		{
			this-> show_status();
			if (update_location())
			{
				this-> state = 'd';
				return true;
			}
			else
			{
				return false;
			}
		}
		case 'd' : // depositing
		{
			this-> show_status();
			std::cout << this-> display_code << this-> get_id() << ": Deposit " 
					  << this-> amount << " of gold." << std::endl;
			this-> home-> deposit_gold(this-> amount); // add gold to hall
			this-> amount = 0; // reset gold being carried to zero

			if (this-> mine-> is_empty())
			{
				// if mine is empty then
				this-> state = 's'; // stop the miner
				std::cout << this-> display_code << this-> get_id() << ": More work?" << std::endl;
				return true;
			}
			else
			{
				// if mine is not empty then go back to mine for more
				setup_destination(this-> mine -> get_location());
				this-> state = 'o'; // outboud again
				std::cout << this-> display_code << this-> get_id() << ": Going back for more." << std::endl;
				return true;
			}
		}
	}
}

// PUBLIC MEMBER FUNCTION
void Miner::show_status()
{
	switch (this-> state)
	{
		case 's' : // stopped
		{
			std::cout << "	Stopped." << std::endl;
			break;
		}
		case 'm' : // moving
		{
			std::cout << "Miner status: ";
			Person::show_status();
			break;
		}
		case 'o' : // outbound
		{
			std::cout << "	Outbound to a mine." << std::endl;
			break;
		}
		case 'g' : // getting gold
		{
			std::cout << "	Getting gold from mine." << std::endl;
			break;
		}
		case 'i' : // inbound
		{
			std::cout << "	Inbound to home with load: " << this-> amount << std::endl;
			break;
		}
		case 'd' : // depositing
		{
			std::cout << "	Depositing gold." << std::endl;
			break;
		}
	}
}

void Miner::start_mining(Gold_Mine * inputMine, Town_Hall * inputHome)
{
	this-> mine = inputMine; // set mine pointer
	this-> home = inputHome; // set home pointer
	setup_destination(this-> mine-> get_location()); // set destination to mine
	this-> state = 'o'; // state is now outbound
	std::cout << "Miner " << this-> get_id() << " mining at Gold_Mine " << this-> mine-> get_id()
			  << " and depositing at Town_Hall " << this-> home-> get_id() << "." << std::endl;
	std::cout << this-> display_code << this-> get_id() << ": Yes, my Lord." << std::endl;
}