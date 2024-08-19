#include <iostream>
using namespace std;

/*
Name: Ethan Dakin
Student Number: 8209194
*/

int main() {
    // Declare variables m and n
    int m, n;

    // Input variables
    cout << "Enter integer m: " << endl;
    cin >> m;

    cout << "Enter integer n: " << endl;
    cin >> n;

    // Check if variables are positive
    if (m < 1 or n < 1) {
        cout << "Integers must be positive values";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        // Print m * i
        cout << m * i;

        // If iteration is not last
        if (i != n) {
            // Print a comma
            cout << ", ";
        }
    }

    cout << endl;

    // Terminate program
    return 0;
}