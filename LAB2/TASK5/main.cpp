#include <iostream>

class MyException : public std::exception{
    public:
        const char * what() const throw() {
            return "Attempted to divide by zero!\n";
        }
};

int main() {
    float x, y;

    std::cout << "Enter the numbers of x and y:" << std::endl;
    std::cin >> x;
    std::cin >> y;

    try {
        if (x == 0 || y == 0) {
            throw MyException();
        }

        std::cout << "x/y = " << x/y << std::endl;
    }
    catch(MyException e) {
        std::cout << e.what();
    }


}