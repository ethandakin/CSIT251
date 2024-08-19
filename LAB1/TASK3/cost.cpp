#include <iostream>

using namespace std;

/*
Name: Ethan Dakin
Student Number: 8209194
*/

// Gets char for material
void get_material(char &material) {
    cout<<"Please enter a material (w, b or c): ";
    cin >> material;

    // If material is not w, b or c then
    if (!(material == 'w' || material == 'b' || material == 'c')) {
        cout<< "Invalid material: " << material << endl;
        // recursively call itself until it passes.
        get_material(material);
    }
}

// Gets user input for measurements
void get_measurements(double &w, double &h, double &d) {
    cout << "Please enter a width: ";
    cin >> w;

    cout << "Please enter a height: ";
    cin >> h;

    cout << "Please enter a depth: ";
    cin >> d;
}

// Returns the price double
double calculate_price(double w, double h, double d, char material) {
    // Declare multiplier
    int m;

    // Switch case for multiplier
    switch(material) {
        case 'w':
            m = 75;
            break;
        case 'c':
            m = 150;
            break;
        case 'h':
            h = 175;
            break;
    }

    return m * (w*d*h) + 200;
}

// Print the cost
void display(int cost) {
    cout << "The final cost is: $" << cost << endl;
}