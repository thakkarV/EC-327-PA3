// ADDS OBJECT BEHAVIOR CHECKING FOR CART POINT AND CART VECTOR

#include <iostream>

#include "Cart_Vector.h"
#include "Cart_Point.h"

using namespace std;
//Students need to build on this
int main()
{

//---------------------------------------------------------------------------------------------------------
// TESTING CHECKPOINT 1 NOW
//---------------------------------------------------------------------------------------------------------
    cout << "NOW TESTING CHECKPOINT 1" << endl << endl;

    Cart_Point p1 = Cart_Point(0, 0);
    if(p1.x != 0 && p1.y != 0)
    {
        cout << "Cart_Point is not working!" << endl;
        return 1;
    }
    
    cout << "P1 is: " << p1 << endl;
    Cart_Vector v1 = Cart_Vector(4,-3);
    Cart_Point p2 = p1+v1;
    cout << "P2 is: " <<  p2 << endl;
    p2 = p2 + v1;
    cout << "P2 + V1 is: " << p2 << endl;
    cout << "V1 is :" << v1 << endl;
    
    double a = 0.0;
    double b = 3.0;
    //creating Cart_Point objects
    Cart_Point p3 (a,b);
    Cart_Point p4;
    
    //checking behavior of non-member functions of Cart_Point.cpp
    cout<<"Distance: "<< cart_distance(p3,p4)<<endl;
    
    //checking behavior of overloading operators defined in Cart_Point.cpp
    cout << "p3= " << p3 << endl;
    
    /* your code here: test '<<', '-', '+' overloaded operators */
    cout << "p1 - p2 is: " << p1-p2 << endl;

            
    //creating Cart_Vector objects
    Cart_Vector v2(5.0, 10.0);
    Cart_Vector v3(15.0, 20.0);
    
    /*your code here: test '<<', '*','/' overloaded operators */
    
    cout << "V2 is : " << v2 << endl;
    cout << "V2 * 2.1 is: " << v2*2.1 << endl;
    cout << "V3 is : " << v3 << endl;
    cout << "V3 / 4 is " << v3/4 << endl;
    cout << "V2 is : " << v2 << endl;
    cout << "V2 / 0 is " << v2/0 << endl;

    return 0;
}