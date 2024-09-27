#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <random>
#include <iomanip>

/*
Name: Ethan Dakin
Student Number: 8209194
*/

// Constant values, max simulated is the maximum number of workers possible.
const int MAX_SIMULATED = 20;
// Delimiters is all the possible characters the specify the end of a word.
const std::string delimiters(",%$;&:");

// Worker struct
struct worker {
    int id;
    std::string name;
    int variability;
    int ability;
    int experienceLabel;
};

// Task struct
struct task {
    int id;
    std::string description;
    int uncertainty;
    int difficulty;
    int priorityLabel;
    int workers[20] = {};
};

// Record struct, includes an array of strings obtained from splitting, and the maximum index in the line.
struct record {
    std::string output[MAX_SIMULATED + 5];
    int index = 0;
};

// write_worker takes a worker variable and inserts it into the workers array
void write_worker(worker w);
// write_task takes a task variable and inserts it into the tasks array
void write_task(task t);
// read_line takes a string and returns a record containing the individual strings found in that line, split by the delimeters.
record read_line(std::string info);
// get_task reads from a record and returns a task.
task get_task(record info);
// get_worker reads from a record and returns a worker.
worker get_worker(record info);
// calculate_performance_score takes a worker and a task, then calculates the average performance score for that worker.
int calculate_performance_score(worker w, task t);
// print_worker_headers prints the format for the initial output.
void print_worker_headers(std::ofstream &outputstream);
// print_worker just outputs the worker to the file
void print_worker(worker w, std::ofstream &outputstream);
// process_task outputs the task and then calculates which workers succeed in this task
void process_task(task t, std::ofstream &outputstream);