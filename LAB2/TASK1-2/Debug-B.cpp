#include <iostream>
#include <cmath>
using namespace std;

/*
Name: Ethan Dakin
Student Number: 8209194
*/

// Min macro expression, which is a ternary expression returning the lower value
#define min(a,b) (a > b) ? b : a

int main(int argc, char* argv[])
{
	// Ensures there are only three arguments
	if (argc != 3)
	{
		cerr << "Enter two integers after the program name please!" << endl;
		return -1;
	}

	// Convert characters to integers
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);

	// c is the Lower input of (a, b)
	int c = min(b,a);
	
	// Print output
	cout << "log10(10) should be 1 : " << log10(10) << endl;
	// e is log(exp(1.0))
	cout << "log(e) should be 1    : " << log(exp(1.0)) << endl;	
	cout << "log of lower input is : " << log(c) << endl;	

	// Terminate program
	return 0;
}
