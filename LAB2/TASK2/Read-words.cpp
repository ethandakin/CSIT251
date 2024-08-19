#include <iostream>
#include <fstream>
#include <string>



int main() {
    std::ifstream input;
    std::ofstream output;
    input.open("Words");
    output.open("output.txt");

    if (!input) {
        std::cout << "File could not be opened" << std::endl;
        return -1;
    }

    if (output.bad()) {
        std::cout << "File could not be opened" << std::endl;
        return -1;
    }

    

    std::string word;
    int index = 1;

    while (input >> word) {
        // as each word is on a seperate line, we dont need to read
        // by line, we can just increment an integer from each word
        output << word << " : " << index << std::endl;
        index++;
    }

    output.close();
    input.close();
    return 0;
}