#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <random>

const int MAX_SIMULATED = 20;
const std::string delimiters(",%$;&:");

int workers_count = 0;
int tasks_count = 0;

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

struct record {
    std::string output[MAX_SIMULATED + 5];
    int index = 0;
};

worker workers[MAX_SIMULATED];
task tasks[MAX_SIMULATED];

record read_line(std::string info) {
    // max size = number of args for task + 20
    record result;

    std::istringstream iss(info);
    std::size_t prev = 0, pos;
    while ((pos = info.find_first_of(delimiters, prev)) != std::string::npos) {
        if (pos > prev) {
            result.output[result.index] = info.substr(prev, pos - prev);
        }
        prev = pos + 1;
        result.index++;
    }

    if (prev < info.length()) {
        result.output[result.index] = info.substr(prev, pos - prev);
    }

    return result;
}

task get_task(record info) {
    task n;

    n.id = std::stoi(info.output[0]);
    n.description = info.output[1];
    n.uncertainty = std::stoi(info.output[2]);
    n.difficulty = std::stoi(info.output[3]);
    n.priorityLabel = std::stoi(info.output[4]);

    for (int i = 6; i < info.index; i++) {
        n.workers[i - 6] = std::stoi(info.output[i]);
    }

    return n;
}

worker get_worker(record info) {
    worker n;

    n.id = std::stoi(info.output[0]);
    n.name = info.output[1];
    n.variability = std::stoi(info.output[2]);
    n.ability = std::stoi(info.output[3]);
    n.experienceLabel = std::stoi(info.output[4]);

    return n;
}

double calculate_performance_score(worker w, task t) {
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(w.ability - t.difficulty, t.uncertainty + w.variability);

    int n = 5 + (t.priorityLabel * 5);
    double total = 0 + (w.experienceLabel * 6);

    for (int i = 0; i < 10; i++) {
        total += distribution(generator);
    }

    return total / n;
}

void print_task(task t) {
    std::cout << "======================================================================" << std::endl;
    std::cout << "processing taskId: ";
    std::cout << "description: ";
    std::cout << "uncertainty: ";
    std::cout << "difficulty: ";
    std::cout << "priority:";
    std::cout << "workers: ";
}

int main(int argc, char* argv[]) {
    if (argc != 4)
	{
		std::cerr << "Enter tasks, workers, and output text file names in, respectively, after the program name." << std::endl;
		return -1;
	}

    std::ifstream taskstream(argv[1]);
    std::ifstream workerstream(argv[2]);
    std::ofstream outputstream(argv[3]);

    std::string line;

    // Read workers
    while (std::getline(workerstream, line)) {

        record info = read_line(line);
        worker w = get_worker(info);
        
        workers[workers_count] = w;
        workers_count++;
    }

    // Read tasks
    std::string newline;
    while (std::getline(taskstream, newline)) {

        record info = read_line(newline);
        task t = get_task(info);
        
        tasks[tasks_count] = t;
        tasks_count++;
        print_task(t);
    }
    


    return 0;
}