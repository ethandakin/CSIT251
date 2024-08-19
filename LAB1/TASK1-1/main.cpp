#include <iostream>
using namespace std;

/*
Name: Ethan Dakin
Student Number: 8209194
*/

// Get two doubles from user inputs and then print their sum and product.
int main()
{
  // Initialize variables
  double val1, val2;
  // Get user input
  cout<<"Enter a value ";
  cin>>val1;
  cout<<"Enter another value ";
  cin>>val2;
  // Print calculations
  cout<<val1<<" + "<<val2<<" = "<<(val1 + val2)<<endl;
  cout<<val2<<" * "<<val2<<" = "<<(val1 * val2)<<endl;

  // Return 0
  return 0;
}
