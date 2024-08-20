#include <iostream>
#include <string>
#include <sstream>

struct worker {
    int id;
    std::string name;
    int variability;
    int ability;
    int experienceLabel;
};

struct task {
    int id;
    std::string description;
    int uncertainty;
    int difficulty;
    int priorityLabel;
    int workers[20];
};

worker workers[20];

const std::string delimiters(",%-$;&:");

std::string* read_line(std::string info) {
    // max size = number of args for task + 20
    static std::string output[27];
    int index = 0;

    std::istringstream iss(info);
    std::size_t prev = 0, pos;
    while ((pos = info.find_first_of(delimiters, prev)) != std::string::npos) {
        if (pos > prev) {
            output[index] = info.substr(prev, pos - prev);
        }
        prev = pos + 1;
        index++;
    }

    if (prev < info.length()) {
        output[index] = info.substr(prev, pos - prev);
    }
    std::cout<< std::endl;

    return output;
}