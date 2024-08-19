#include <iostream>
#include <fstream>

/*



*/

struct worker {
    int id;
    char name[10];
    int variability;
    int ability;
    int experienceLabel;
};

worker get_worker(std::string line) {
    
}

int main() {
    std::ifstream fin;
    fin.open("Workers.txt");

    std::string line;
    while (std::getline(fin, line)) {
        std::cout << line << std::endl;
    }

    return 0;
}