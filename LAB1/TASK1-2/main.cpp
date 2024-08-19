#include <iostream>
#include "mylibrary.h"

using namespace std;

/*
Name: Ethan Dakin
Student Number: 8209194
*/

int main()
{
    // These comments reflect what the program should do.
    // functionOne should take 3 integers from the user.
    // functionTwo should calculate the sum of those 3 integers.

    // Initialize variables
    int one, two, three, sum;
    // Call functionOne
    functionOne(one, two, three);
    // Declare sum
    sum = functionTwo(one, two, three);

    // Print the sum
    cout<<"The sum of "<<one << " " <<two << " "<<three<<" is "<<sum<<endl;

    // Terminate program
    return 0;
}
