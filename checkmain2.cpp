// ADDS OBJECT BEHAVIOR CHECKING FOR GOLD MINE AND CONSEQUENTLY GAME OBJECT

#include <iostream>

#include "Cart_Point.h"
#include "Game_Object.h"
#include "Gold_Mine.h"

using namespace std;



int main()
{
//---------------------------------------------------------------------------------------------------------
// TESTING CHECKPOINT 2 NOW
//---------------------------------------------------------------------------------------------------------
    cout << endl << endl << "NOW TESTING CHECKPOINT 2" << endl;

// now testing defuault constructor together with show_status and dig gold
    cout << endl << "Making defualt mine with defualt constructor first and testing all operators" << endl << endl;

    Gold_Mine M1 = Gold_Mine();
    cout << "Current status of default mine 1 is " << endl;
    M1.show_status();
    cout << "Diggin default amount of gold from mine" << endl;
    double duggold = M1.dig_gold();
    cout << duggold << " gold dug from mine, New status of mine is " << endl;
    M1.show_status();
    cout << "Diggin 25 gold from mine" << endl;
    duggold = M1.dig_gold(25);
    cout << duggold << " gold dug from mine, New status of mine is " << endl;
    M1.show_status();

// now testing input based constructor together with show_status and dig gold
    cout << endl << "Making custom mine now with input based constructor and testing all operators" << endl << endl;

    Gold_Mine M2 = Gold_Mine(5, Cart_Point(4,2));
    cout << "Current status of custom mine 2 is " << endl;
    M2.show_status();
    cout << "Diggin default amount of gold from mine" << endl;
    duggold = M2.dig_gold();
    cout << duggold << " gold dug from mine, New status of mine is " << endl;
    M2.show_status();
    cout << "Diggin 15 gold from mine" << endl;
    duggold = M2.dig_gold(15);
    cout << duggold << " gold dug from mine, New status of mine is " << endl;
    M2.show_status();


// now testing is_empty and update member functions
    cout << endl << "Now emptying gold mine 1 " << endl << endl;
    duggold = M1.dig_gold(40);
    if (M1.is_empty()) // first check if isempty work as inteded
    {
        if (M1.update()) // then check if update works as intended
        {
            cout << "Current status of default mine 1 is " << endl;
            M1.show_status();
        }
        else
        {
            cout << "Update did not work correctly the first time." << endl;
            return 0;
        }
        // check if update works the second time and returns flase
        if (!M1.update())
        {
            cout << "Update only retruns true once. Update behaves as expected." << endl;
        }
        else
        {
            cout << "Update did not work correctly the second time." << endl;
            return 0;
        }
    }
    else
    {
        cout << "is_empty does not work as intended. Check Gold_Mine.cpp" << endl;
        return 0; 
    }


    // all tests passed?
    cout << "Checkpoint1 passed. GG" << endl;
    return 0;
}