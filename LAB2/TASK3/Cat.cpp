#include <iostream>
#include <string>

struct Cat {
    std::string name, breed;
    int age;
    static constexpr float insurance = 99.9;
    float price;

    void setCat(std::string catName, std::string catBreed, int catAge) {
        name = catName;
        breed = catBreed;
        age = catAge;
    }

    void calculatePrice() {
        price = age * 1.5 + insurance;
    }

    void showCat() {
        std::cout << "Cat: " << name << " is a " << breed << std::endl;
        std::cout << "Its age is " << age << std::endl;
        std::cout << "Insurance fee: " << insurance << std::endl;
        std::cout << "Owing cost is: " << price << std::endl;
    }
};

int main() {
    Cat myCat;
    myCat.setCat("Tiger", "British Shorthair", 1);
    myCat.calculatePrice();
    myCat.showCat();

    return 0;
}