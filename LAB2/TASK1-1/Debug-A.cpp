#include <iostream>
using namespace std;

/*
Name: Ethan Dakin
Student Number: 8209194
*/

void countDown(int highest, int lowest);

// Prints integers from highest to lowest, inclusive.

int main()
{
   // Get user input
   int high, low, temp;

   cout << "Enter an integer ";
   cin >> high;

   cout << "Enter another integer ";
   cin >> low;

   // Swap variables if low is greater than high
   if (high < low)
   {
       temp = high;
       high = low;
       low = temp;
   }

   // Print the values from high to low
   countDown(high, low);

   // Terminate program
   return 0;
}

void countDown(int highest, int lowest)
{
   // Print from highest to lowest
   for (int x = highest; x >= lowest; x--) {
      cout << x << " " << endl;
   }
}
