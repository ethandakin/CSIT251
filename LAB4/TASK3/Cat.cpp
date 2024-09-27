#include<iostream>
#include<string>
using namespace std;

class Animal {
   
};

class Dog: public Animal {

}

class Cat: public Animal {
   private:
      string name;
      string breed;
      int age;
      static constexpr double licenseFee = 10;

   public:
      void setCatData(string, string, int);
      void showCat();
};
//const double Cat::licenseFee = 10;

void Cat::setCatData(string catName, string catBreed, int catAge)
{
   name = catName;
   breed = catBreed;
   age = catAge;
}

void Cat::showCat()
{
  cout << "Cat: " << name << " is a " << breed << endl;
  cout << "The cat's age is " << age << endl;
  cout << "License fee: $" << licenseFee << endl;
}

int main()
{
     Cat myCat;
     myCat.setCatData("Tigger", "Fluffy unit", 3);
     myCat.showCat();
}

