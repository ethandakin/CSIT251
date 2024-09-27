#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <random>

class Issue {
	private:
		std::string name, description;
	public:
		Issue(std::string _name, std::string _description) : name(_name), description(_description) {}
};

const std::vector<Issue> issues = {
		Issue("Climate change", ""),
		Issue("Free healthcare", ""),
		Issue("Food insecurity", ""),
		Issue("Equality", ""),
		Issue("Mental health", "")
};

class Stance {
	private:
		Issue *issue;
	public:
		double stance[2];
		Stance() {};
		Stance(Issue *_issue, double significance, double strength) {
			stance[0] = significance;
			stance[1] = strength;
			issue = _issue;
		}
};

class Politician {
	double popularity;
};

class Leader: public Politician {

};

class Candidate: public Politician {
	private:
		std::vector<Stance> stances;
};

class Party {
	private:
		Leader leader;
		std::vector<Candidate> candidates;
	public:
		Party() {};

};

const double get_random(double min, double max) {
	std::random_device random;
	std::mt19937 generator(random());
	std::uniform_real_distribution<> distribution(min, max);

	return distribution(generator);
}

class Division {
	private:
		double population;
		std::vector<Stance> stances;
	public:
		Division() {
			population = get_random(0.5, 1.5);

			for (int i = 0; i < 5; i++) {
				Issue issue = issues[i];
				stances[i] = Stance(&issue, get_random(0.0, 1.0), get_random(0.0, 1.0));
			}
		}

		double getPopulation() const {
			return population;
		}

		std::vector<Stance> getStances() const {
			return stances;
		}
};

double calculateCosineSimularity(Stance x, Stance y) {
	double x1 = x.stance[0];
	double x2 = x.stance[1];

	double y1 = y.stance[0];
	double y2 = y.stance[1];

	return ((x1 * y1) + (x2 * y2)) / (sqrt(pow(x1, 2) + pow(x2, 2)) * sqrt(pow(y1, 2) + pow(y2, 2)));
}


int main(int argc, char* argv[]) {
	// Ensures there are only three arguments
	if (argc != 3)
	{
		std::cerr << "Enter two integers after the program name please!" << std::endl;
		return -1;
	}

	int n_divisions = atoi(argv[1]);
	int days = atoi(argv[2]);

	if (n_divisions < 1 || n_divisions > 10) {
		std::cerr << "Divisions must be between 1 and 10 inclusive." << std::endl;
		return -1;
	}

	if (days < 1 || days > 30) {
		std::cerr << "Days must be between 1 and 30 inclusive." << std::endl;
		return -1;
	}
	
	// create parties
	Party parties[3];
	std::vector<Division> divisions;

	// create divisions

	for (int i = 0; i < n_divisions; i++) {
		divisions.push_back(Division());
	}

	// create leader

	for (int i = 0; i < 3; i++) {
		// for each party


	}


	// create candidates
	





	// campaign event days

	for (int i = 0; i < days; i++) {
		// for each division, one local event will happen

	}

	// election day


    return 0;
}