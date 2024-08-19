#include <iostream>
using namespace std;

/*
Name: Ethan Dakin
Student Number: 8209194
*/

void functionOne(int &one, int &two, int &three)
{
	// Get three integers from user
	cout << "Enter the first integer : ";
	cin >> one;

	cout << "Enter the second integer : ";
	cin >> two;

	cout << "Enter the third integer : ";
	cin >> three;
}

int functionTwo(int one, int two, int three)
{
	// Return sum of three integers
	return one + two + three;
}
