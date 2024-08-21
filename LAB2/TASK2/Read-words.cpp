#include <iostream>
#include <fstream>
#include <string>

/*
Name: Ethan Dakin
Student Number: 8209194
*/

// This program reads from a file named Words and writes to a file output.txt, 
// writing the word read and the line it was read from.
int main() {
    std::ifstream input;
    std::ofstream output;
    input.open("Words");
    output.open("output.txt");

    // Ensure both input and output are openable files
    if (!input) {
        std::cout << "File could not be opened" << std::endl;
        return -1;
    }

    if (output.bad()) {
        std::cout << "File could not be opened" << std::endl;
        return -1;
    }

    // Create empty string
    std::string word;
    // Index counter for line
    int index = 1;

    while (input >> word) {
        // As each word is on a seperate line, we dont need to read
        // by line, we can just increment an integer from each word
        output << word << " : " << index << std::endl;
        index++;
    }

    // Close input and output
    output.close();
    input.close();

    // Terminate program
    return 0;
}