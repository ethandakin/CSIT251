#include<iostream>
#include<string>

using namespace std;

class Painting {
   protected:
      string title;
      string artist;
      int value;
   public:
      Painting() {

      };
      Painting(string name, string painter);
      void showPainting();
      void setData();
      string getArtist();
      string getTitle();
};

Painting::Painting(string name, string painter) {
   title = name;
   artist = painter;
   value = 400;
}

void Painting::setData() {
   cout<<"Enter painting's title ";
   cin>>title;
   cout<<"Enter artist ";
   cin>>artist;
   value = 400;
}

void Painting::showPainting() {
   cout<<title << " by " <<artist<<" value $" << value << endl;
}

string Painting::getArtist() {
   return artist;
}

string Painting::getTitle() {
   return title;
}

class FamousPainting: public Painting {
   public:
      FamousPainting(string name, string painter);
};

FamousPainting::FamousPainting(string name, string painter) : Painting(name, painter) {value = 25000;}

bool isPaintingFamous(Painting p) {
   bool isFamous = false;

   const int NUM = 4;
   string artists[NUM] = {"Degas","Monet","Picasso","Rembrandt"};

   for(int x = 0; x <= NUM; ++x) {
      if (p.getArtist() == artists[x]) {
         isFamous = true;
         break;
      }
   }

   return isFamous;
}

int main() {
   const int NUM = 4;
   Painting pictures[NUM];
   for(int x = 0; x < NUM; ++x) {
      Painting temp;
      temp.setData();

      if(isPaintingFamous(temp)) {
         FamousPainting tempF(temp.getTitle(), temp.getArtist());
         temp = tempF;
      }

      pictures[x] = temp;
   }

   std::cout << endl;

   for(int x = 0; x < NUM; x++) {
      pictures[x].showPainting();
   }
}
