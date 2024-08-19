#include <iostream>
#include <fstream>
using namespace std;

int main()
{
   int bookid;
   string name;
   double price;  

   const string note1 = "Enter ID, name, and price";
   const string note2 = "Enter end-of-file key combination (Ctrl-d) to end ";

   ofstream outFile;
   outFile.open("library.txt");

   if (outFile.bad()) {
      cout << "File could not be opened" << endl;
      return -1;
   }

   cout << note1 << endl;
   cout << note2 << endl;

   while ( cin >> bookid >> name >> price)
   {
      outFile << bookid << " " << name << " " << price << endl;
      cout << bookid << endl << name << price << endl;
   }
   
   outFile.close();

   return 0;
}
