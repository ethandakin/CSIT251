#include <iostream>
#include <string>

/*
Name: Ethan Dakin
Student Number: 8209194
*/

// Cat struct for program
struct Cat {
    std::string name, breed;
    int age;
    // Please note, when I was trying to make this
    // a static const float, it was saying it needed to be a constexpr.
    static constexpr float insurance = 99.9;
    float price;

    void setCat(std::string catName, std::string catBreed, int catAge) {
        // Set the variables of the struct
        name = catName;
        breed = catBreed;
        age = catAge;
    }

    void calculatePrice() {
        // Calculate the price
        price = age * 1.5 + insurance;
    }

    void showCat() {
        // Print the cat information
        std::cout << "Cat: " << name << " is a " << breed << std::endl;
        std::cout << "Its age is " << age << std::endl;
        std::cout << "Insurance fee: " << insurance << std::endl;
        std::cout << "Owing cost is: " << price << std::endl;
    }
};

int main() {
    // Create cat
    Cat myCat;
    myCat.setCat("Tiger", "British Shorthair", 1);
    myCat.calculatePrice();
    myCat.showCat();

    // Terminate program
    return 0;
}