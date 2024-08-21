#include <iostream>

/*
Name: Ethan Dakin
Student Number: 8209194
*/

// Exception class
class MyException : public std::exception{
    public:
        const char * what() const throw() {
            // Return when attempted to divide by zero
            return "Attempted to divide by zero!\n";
        }
};

int main() {
    float x, y;

    // Get user input
    std::cout << "Enter the numbers of x and y:" << std::endl;
    std::cin >> x;
    std::cin >> y;

    try {
        // Throw the error if a float is 0
        if (x == 0 || y == 0) {
            throw MyException();
        }

        // Print the value
        std::cout << "x/y = " << x/y << std::endl;
    }
    // Catch exception
    catch(MyException e) {
        std::cout << e.what();
    }
}