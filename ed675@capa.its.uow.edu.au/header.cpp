#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <random>
#include <iomanip>
#include "header.h"

/*
Name: Ethan Dakin
Student Number: 8209194
*/

// Initialize counts for each worker and task
int workers_count = 0;
int tasks_count = 0;

// Initialize the arrays for each worker and task
// MAX_SIMULATED is declared in header.h
worker workers[MAX_SIMULATED];
task tasks[MAX_SIMULATED];


// Function to read each string line
record read_line(std::string info) {
    // max size = number of args for task + 20
    record result;

    // Get the istringstream from the input string
    std::istringstream iss(info);
    std::size_t prev = 0, pos;
    // While the current position in the string is a delimeter and is not the end of the string
    while ((pos = info.find_first_of(delimiters, prev)) != std::string::npos) {
        // If the position is greater than previous
        if (pos > prev) {
            // Add the substring to the output array
            result.output[result.index] = info.substr(prev, pos - prev);
        }
        // Increment prev by pos + 1
        prev = pos + 1;
        // Increment the index
        result.index++;
    }

    // If the previous position is less than the length of the string
    if (prev < info.length()) {
        // The last added word is the substring of prev to position - prev
        result.output[result.index] = info.substr(prev, pos - prev);
    }

    // Return record result
    return result;
}

// Get the task for string info
task get_task(record info) {
    // Initialize task
    task n;

    // Convert the number based ones to integers
    n.id = std::stoi(info.output[0]);
    n.description = info.output[1];
    n.uncertainty = std::stoi(info.output[2]);
    n.difficulty = std::stoi(info.output[3]);
    n.priorityLabel = std::stoi(info.output[4]);

    // For int i = 6 (index 5 is "workers"), and i is less than index (maximum size of string)
    for (int i = 6; i <= info.index; i++) {
        // Add the correct index to workers array
        n.workers[i - 6] = std::stoi(info.output[i]) + 1;
    }

    // Return task
    return n;
}

worker get_worker(record info) {
    // Initialize worker
    worker n;

    // Convert the strings to integers for necessary ones
    n.id = std::stoi(info.output[0]) + 1; // Note, I added 1 to the worker ID in the struct. This is due to how I find the end index of workers.
    n.name = info.output[1];
    n.variability = std::stoi(info.output[2]);
    n.ability = std::stoi(info.output[3]);
    n.experienceLabel = std::stoi(info.output[4]);

    // Return worker
    return n;
}

// Adds a worker to the worker array
void write_worker(worker w) {
    workers[workers_count] = w;
    // Increment worker count
    workers_count++;
}

// Adds a task to the task array
void write_task(task t) {
    tasks[tasks_count] = t;
    // Increment task count
    tasks_count++;
}

// Used to calculate the performance score for a worker and a task.
int calculate_performance_score(worker w, task t) {
    // Create the default random engine for the normal distribution
    std::default_random_engine generator;
    // Create the normal distribution function, which returns a double. Note the mean is equal to the
    // Worker's ability - the task difficulty, and the standard deviation is the task's uncertainty
    // plus the worker's variability
    std::normal_distribution<double> distribution(w.ability - t.difficulty, t.uncertainty + w.variability);

    // The amount of samples drawn is n + t.priorityLabel * 5
    // as t.priorityLabel can only be 1 or 0, it will either be 0 or 5.
    int n = 5 + (t.priorityLabel * 5);
    // Create total variable
    double total = 0;

    // For n times
    for (int i = 0; i < n; i++) {
        // Add the sample to the total
        total += distribution(generator);
    }

    // Return the ceiling number of the total divided by n (the average) with an addition of
    // either a 0 or a 6.
    return (int) std::ceil((total / n) + (w.experienceLabel * 6));
}

// Print the headers for the worker info
void print_worker_headers(std::ofstream &outputstream) {
    outputstream 
    << "WorkerID" << std::setw(10)
    << "Name" << std::setw(20)
    << "Variability" << std::setw(8)
    << "Ability" << std::setw(20)
    << "ExperienceLabel"
    << std::endl;
}

// Print the worker information
void print_worker(worker w, std::ofstream &outputstream) {
    outputstream 
    << std::setw(14) << std::left << w.id - 1
    << std::setw(13) << std::left << w.name
    << std::setw(12) << std::left << w.variability
    << std::setw(12) << std::left << w.ability
    << std::left << w.experienceLabel
    << std::endl;
}

void process_task(task t, std::ofstream &outputstream) {
    // Print the task info
    outputstream << "======================================================================" << std::endl;
    outputstream << "processing taskId:  " << t.id << "\n"
    << "description :   " << t.description << "\n"
    << "uncertainty :   " << t.uncertainty << "\n"
    << "difficulty  :   " << t.difficulty << "\n"
    << "priority    :   " << t.priorityLabel << "\n"
    << "workers     :   ";

    // For up to 20,
    for (int i = 0; i < 20; i++) {
        // If the worker is equal to 0 then break loop (workers index starts from 1.)
        if (t.workers[i] == 0) {
            break;
        }

        // Output the worker id
        outputstream << t.workers[i] - 1;

        // If the next one is not 0 then output a comma too.
        if (t.workers[i + 1] != 0) {
            outputstream << ',';
        }
    }

    // Output an empty line
    outputstream << std::endl;

    // Initialize variable for total workers count
    int n = 0;

    for (int i = 0; i < 20; i++) {
        if (t.workers[i] == 0) {
            break;
        }

        // If the worker value is not 0 then add 1 to n.
        n++;
    }

    outputstream << std::endl;

    // For each worker in the workers list.
    for (int i = 0; i < n; i++) {
        // All outputs are indented by 1 tab.
        outputstream << "\t----------------------------------------------" << std::endl;
        // Output trial number
        outputstream << "\tTrial (" << i + 1 << '/' << n << "), ";

        // Get the worker
        worker w = workers[t.workers[i] - 1];

        // Output the correct title for the worker
        if (w.experienceLabel == 1) {
            outputstream << "Senior ";
        } else {
            outputstream << "Ordinary ";
        }

        // Output the worker ID
        outputstream << "worker  : " << t.workers[i] - 1 << std::endl;

        // Output a line
        outputstream << "\t----------------------------------------------" << std::endl;

        // Calculate the performance
        int performance = calculate_performance_score(w, t);

        // Output the performance
        outputstream << "\tThe average performance is " << performance << std::endl;
        outputstream << "\tAssignment of Task " << t.id << " to worker " << w.id - 1;

        // If the performance is less than 50, it fails and goes again
        if (performance <= 50) {
            outputstream << " fails" << std::endl;
        } else {
        // Else, stop the loop and print success.
            outputstream << " succeeds" << std::endl;
            break;
        }

        // Print an empty line
        outputstream << std::endl;
    }

    // Print an empty line.
    outputstream << std::endl;
}