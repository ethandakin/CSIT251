#include <iostream>
// Include cost library
#include "cost.h"

// Gets a material character and 3 dimensions from the user, then calculates
// the appropriate price.
int main() {
    // Initialize variables
    char m;
    double w, d, h;

    // Get user input for material
    get_material(m);

    // Get user input for measurements
    get_measurements(w, d, h);

    // Display the calculated price
    display(calculate_price(w, d, h, m));

    // Terminate program
    return 0;
}