// Include iostream and header
#include <iostream>
#include "header.h"

/*
Name: Ethan Dakin
Student Number: 8209194
*/

int main(int argc, char* argv[]) {
    // Ensure main has 4 arguments
    if (argc != 4)
	{
        // Return error message if the arguments aren't specified
		std::cerr << "Enter tasks, workers, and output text file names in, respectively, after the program name." << std::endl;
		return -1;
	}

    // Open files and correct error handling assuming we cannot open each file.
    std::ifstream taskstream(argv[1]);
    if (!taskstream) {
        std::cerr << "Error opening file " << argv[1] << ". Program will exit." << std::endl;
        return -1;
    }

    std::ifstream workerstream(argv[2]);
    if (!workerstream) {
        std::cerr << "Error opening file " << argv[2] << ". Program will exit." << std::endl;
        return -1;
    }

    std::ofstream outputstream(argv[3]);
    if (!outputstream) {
        std::cerr << "Error opening file " << argv[3] << ". Program will exit." << std::endl;
        return 0;
    }

    // Initialize line
    std::string line;

    // Print the worker headers
    print_worker_headers(outputstream);

    // Read each line
    while (std::getline(workerstream, line)) {
        // Get the record info from each line
        record info = read_line(line);
        // Get the worker from the record
        worker w = get_worker(info);
        // Write the worker to the workers array
        write_worker(w);
        // Print the worker
        print_worker(w, outputstream);
    }

    // Output an empty line
    outputstream << std::endl;
    // Close workerstream
    workerstream.close();

    // Read tasks
    std::string newline;
    while (std::getline(taskstream, newline)) {
        // Get the record info for each task
        record info = read_line(newline);
        // Get the task from the record info
        task t = get_task(info);
        // Write the task
        write_task(t);
        // Print and process the task for each worker
        process_task(t, outputstream);
    }

    // Close the task stream
    taskstream.close();
    // Close the output stream
    outputstream.close();
    // Terminate the program
    return 0;
}