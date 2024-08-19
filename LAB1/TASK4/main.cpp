#include <iostream>
// Could have used library cmath, but I did not see it in any lecture content.
using namespace std;

/*
Name: Ethan Dakin
Student Number: 8209194
*/

// Declare pi constant
const double pi = 3.14159265358979323846;
// NOTE: This is 21 digits of pi, from the cmath library directly.

int main(){
    // Declare radius, area and circumference
    double r, s, v;
    
    // Input radius
    cout << "input the radius" << endl;
    cin >> r;

    // s = pi * r^2
    s = pi * (r*r);
    // v = 2*pi*r
    v = 2 * pi * r;

    // Print values
    cout << "the area of the circle is:" << endl;
    cout << s << endl;
    cout << "the circumference of this circle is:" << endl;
    cout << v << endl;

    // Terminate program
    return 0;
}