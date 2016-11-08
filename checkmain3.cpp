// ADDS OBJECT BEHAVIOR CHECKING FOR TOWN HALL

#include <iostream>

#include "Cart_Point.h"
#include "Game_Object.h"
#include "Town_Hall.h"

using namespace std;

int main()
{
//---------------------------------------------------------------------------------------------------------
// TESTING CHECKPOINT 3 NOW
//---------------------------------------------------------------------------------------------------------
	cout << endl << endl << "NOW TESTING CHECKPOINT 3" << endl;

// creating a default townhall
	cout << "Testing default constructor and member function behavior" << endl;
	Town_Hall t1 = Town_Hall();
	t1.show_status();
	cout << "Now tesing deposit_gold function by adding 25 gold to t1" << endl;
	t1.deposit_gold(25); 
	t1.show_status();

	// false positive pre trigger test
	if (t1.update())
	{
		cout << "Abberent behavior of update function. True even if gold inside is less than 50." << endl;
		return 0;
	}

	// make upgrade worthy
	cout << "Now tesing deposit_gold function by adding 35 gold to t1" << endl;
	t1.deposit_gold(35);

	// false negative test
	if (!t1.update())
	{
		cout << "Abberent behavior of update function. False even if gold inside is more than 50." << endl;
		return 0;
	}

	// flase positive post trigger test
	if (t1.update())
	{
		cout << "Abberent behavior of update function. True even if upgraded already." << endl;
		return 0;
	}

	t1.show_status();

	cout << endl << endl << "Testing input based constructor behavior" << endl;
	cout << "Input id is 7 and location is 2,3" << endl;
	Town_Hall t2 = Town_Hall(7, Cart_Point(2,3));
	t2.show_status();

	cout << endl << "Checkpoint 3 hopefully passed. GG" << endl;
    return 0;
}