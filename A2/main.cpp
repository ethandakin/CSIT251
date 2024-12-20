#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <algorithm>

/*
Name: Ethan Dakin
Student Number: 8209194
*/

// Function to get a random double from a min to max
double get_random(double min, double max) {
	std::random_device random;
	std::mt19937 generator(random());
	std::uniform_real_distribution<> distribution(min, max);

	return distribution(generator);
}

// Get a random integer
int get_random_int(int min, int max) {
	std::random_device random;
	std::mt19937 generator(random());
	std::uniform_real_distribution<> distribution(min, max);

	return distribution(generator);
}

// Issue class
class Issue {
	private:
		std::string name, description;
	public:
		Issue(std::string _name, std::string _description) : name(_name), description(_description) {}

		// Getters and setters
		std::string getName() const {
			return name;
		}

		std::string getDescription() const {
			return description;
		}

		void setName(std::string _name) {
			name = _name;
		}

		void setDescription(std::string _description) {
			description = _description;
		}
};

// Create issues vector
const std::vector<Issue> issues = {
		Issue("Climate change", "Climate change is important because it affects the environment, as well as both natural and human systems, including economic conditions."),
		Issue("Free healthcare", "Universal health coverage allows countries to make the most of their strongest asset, which is the citizens. Supporting health represents an investment in human capital and economic growth."),
		Issue("Food security", "Food securtity is a powerful tool in the battle against poverty, and is an essential part of everybody's day to day life."),
		Issue("Equality", "Equality and diversity practices ensure that everyone is treated as equals, and are given the dignity and respect they deserve."),
		Issue("Mental health", "Mental health is an important factor in people's lives, as it helps them determine how to handle stress, relate to others and make healthy choices.")
};

// Stance class
class Stance {
	private:
		Issue *issue;
		double significance, strength;
	public:
		// Constructors
		Stance(Issue *_issue) {
			issue = _issue;
			// Random values between 0.0 and 1.0
			significance = get_random(0.0, 1.0);
			strength = get_random(0.0, 1.0);
		}

		Stance(Issue *_issue, double _significance, double _strength) : issue(_issue), significance(_significance), strength(_strength) {}

		// Getters and setters
		double getSignificance() const {
			return significance;
		}

		double getStrength() const {
			return strength;
		}

		Issue* getIssue() const {
			return issue;
		}

		void setSignifcance(double _significance) {
			significance = std::clamp(_significance, 0.0, 1.0);
		}

		void setStrength(double _strength) {
			strength = std::clamp(_strength, 0.0, 1.0);
		}
};

// Base politician class
class Politician {
	private:
		double popularity = 0.0;
	public:
	// Get and set popularity
		double getPopularity() const {
			return popularity;
		}

		void setPopularity(double _popularity) {
			popularity = std::clamp(_popularity, 0.0, 1.0);
		}
};

// Leader class, doesnt really have much in it.
class Leader: public Politician {
	public:
		Leader() {};	
};

// Candidate class
class Candidate: public Politician {
	private:
		std::vector<Stance> stances;
	public:
		// Constructor
		Candidate(std::vector<Stance> _stances) : stances(_stances) {};

		// Get stance(s)
		std::vector<Stance> getStances() const {
			return stances;
		}

		Stance getStance(int i) const {
			return stances.at(i);
		}
};

// Party class
class Party {
	private:
		Leader leader;
		std::vector<Candidate> candidates;
	public:
		Party() {};
		Party(Leader _leader) : leader(_leader) {};

		Leader getLeader() const {
			return leader;
		}

		std::vector<Candidate> getCandidates() const {
			return candidates;
		}

		Candidate getCandidate(int i) const {
			return candidates.at(i);
		}

		void addCandidate(Candidate candidate) {
			candidates.push_back(candidate);
		}
};

// Division class
class Division {
	private:
		double population;
		std::vector<Stance> stances;
	public:
		Division() {
			// Population is a random double between 0.5 and 1.5
			population = get_random(0.5, 1.5);

			for (int i = 0; i < 5; i++) {
				// Create stances
				Issue issue = issues.at(i);
				stances.push_back(Stance(&issue));
			}
		}

		double getPopulation() const {
			return population;
		}

		std::vector<Stance> getStances() const {
			return stances;
		}

		Stance getStance(int i) const {
			return stances.at(i);
		}
};

// Cosine Similarity function
double calculateCosineSimilarity(Stance x, Stance y) {
	double x1 = x.getSignificance();
	double x2 = x.getStrength();

	double y1 = y.getSignificance();
	double y2 = y.getStrength();

	return ((x1 * y1) + (x2 * y2)) / (sqrt(pow(x1, 2) + pow(x2, 2)) * sqrt(pow(y1, 2) + pow(y2, 2)));
}

double calculateStanceAndPopularityFactor(Candidate c, Division d) {
	double info = 0;

	for (int i = 0; i < 5; i++) {
		// for each stance, calculate the similarity between the candidate and division
		info += calculateCosineSimilarity(c.getStance(i), d.getStance(i));
	}

	return info / 5;
}

int main(int argc, char* argv[]) {
	// ensure there are 3 arguments
	if (argc != 3)
	{
		std::cerr << "Enter two integers after the program name please!" << std::endl;
		return -1;
	}

	// convert to integers
	int n_divisions = atoi(argv[1]);
	int days = atoi(argv[2]);

	// checking inputs
	if (n_divisions < 1 || n_divisions > 10) {
		std::cerr << "Divisions must be between 1 and 10 inclusive." << std::endl;
		return -1;
	}

	if (days < 1 || days > 30) {
		std::cerr << "Days must be between 1 and 30 inclusive." << std::endl;
		return -1;
	}
	
	// initialize vectors for parties and divisions
	std::vector<Party> parties;
	std::vector<Division> divisions;

	// create divisions
	for (int i = 0; i < n_divisions; i++) {
		divisions.push_back(Division());
	}

	// create parties and candidates
	for (int i = 0; i < 3; i++) {
		// create leader
		Leader leader;
		Party party(leader);

		// temporary 2 dimensional array for the same stance values for each candidate
		double temp[5][2];

		for (int j = 0; j < 5; j++) {
			temp[j][0] = get_random(0.0, 1.0);
			temp[j][1] = get_random(0.0, 1.0);
		}


		for (int j = 0; j < n_divisions; j++) {
			std::vector<Stance> initial_stances;

			for (int y = 0; y < 5; y++) {
				Issue issue = issues.at(y);
				initial_stances.push_back(Stance(&issue, temp[y][0], temp[y][1]));
			}

			// create candidate with stance vector constructor
			party.addCandidate(Candidate(initial_stances));
		}

		// add party to parties vector.
		parties.push_back(party);
	}

	// Printing outputs
	std::cout << "ISSUES OUTLINE: " << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << "ISSUE " << i + 1 << ":" << std::endl;
		std::cout << "\tNAME = " << issues.at(i).getName() << std::endl;
		std::cout << "\tDESCRIPTION = " << issues.at(i).getDescription() << std::endl;
		
	}

	std::cout << std::endl << "PARTY REPORT:" << std::endl;
	for (int i = 0; i < 3; i++) {
		Party party = parties.at(i);
		std::cout << "PARTY " << i + 1  << ":" << std::endl;
		std::cout << "LEADER: " << std::endl;
		std::cout << "\tPOPULARITY = " << party.getLeader().getPopularity() << std::endl;

		std::vector<Candidate> candidates = party.getCandidates();

		for (int j = 0; j < candidates.size(); j++) {
			std::cout << "CANDIDATE " << j + 1 << ": " << std::endl;
			std::cout << "\tPOPULARITY = " << candidates.at(i).getPopularity() << std::endl;
			
			for (int y = 0; y < 5; y++) {
				std::cout << "\tSTANCE " << y + 1 << ": " << std::endl; 
				std::cout << "\t\tSTRENGTH = " << candidates.at(i).getStance(y).getStrength() << std::endl;
				std::cout << "\t\tSIGNIFICANCE = " << candidates.at(i).getStance(y).getSignificance() << std::endl;
			}

		}

		std::cout << std::endl;
	}

	std::cout << "NATION REPORT: " << std::endl;

	for (int i = 0; i < n_divisions; i++) {
		std::cout << "DIVISION " << i + 1  << ":" << std::endl;
		std::cout << "\tPOPULATION = " << divisions.at(i).getPopulation() << " MILLION" << std::endl;

		for (int y = 0; y < 5; y++) {
				std::cout << "\tSTANCE " << y + 1 << ": " << std::endl; 
				std::cout << "\t\tSTRENGTH = " << divisions.at(i).getStance(y).getStrength() << std::endl;
				std::cout << "\t\tSIGNIFICANCE = " << divisions.at(i).getStance(y).getSignificance() << std::endl;
		}

		std::cout << std::endl;
	}

	std::cout << "DAY SIMULATION: " << std::endl;

	for (int i = 0; i < days; i++) {
		std::cout << "DAY " << i + 1 << ": " << std::endl;

		for (int y = 0; y < n_divisions; y++) {
			std::cout << "\tDIVISION " << y + 1 << ": " << std::endl;
			// event is random double between 0.0 and 1.0
			double event = get_random(0.0, 1.0);
			std::cout << "\t\tEVENT = " << event << std::endl;

			// 20% chance of nothing happening
			if (event < 0.2) {
				continue;
			}

			// rest of events are evenly distributed
			if (event > 0.2 && event < 0.4) {
				std::cout << "\t\tIMPACTING CANDIDATE POPULARITY" << std::endl;

				// all of these work by getting random incrementers and adjusting the popularity or stance slightly..
				int chosen_party = get_random_int(0, parties.size());
				Party party = parties.at(chosen_party);

				int chosen_candidate = get_random_int(0, party.getCandidates().size());
				Candidate candidate = party.getCandidate(chosen_candidate);

				double previous_popularity = candidate.getPopularity();

				candidate.setPopularity(previous_popularity + get_random(-0.1, 0.1));

				std::cout << "\t\t\tCANDIDATE " << chosen_candidate + 1 << " IN PARTY " << chosen_party + 1 << " CHANGED POPULARITY FROM " << previous_popularity << " TO " << candidate.getPopularity() << std::endl;

			} else if (event > 0.4 && event < 0.6) {
				std::cout << "\t\tIMPACTING CANDIDATE STANCE" << std::endl;

				int chosen_party = get_random_int(0, parties.size());
				Party party = parties.at(chosen_party);

				int chosen_candidate = get_random_int(0, party.getCandidates().size());
				Candidate candidate = party.getCandidate(chosen_candidate);

				int chosen = get_random_int(0, 2);
				double increment = get_random(-0.1, 0.1);
				int chosen_stance = get_random_int(0, candidate.getStances().size());
				Stance stance = candidate.getStance(chosen_stance);

				std::cout << "\t\t\tCANDIDATE " << chosen_candidate + 1 << " STANCE " << chosen_stance + 1 << " IN PARTY " << chosen_party + 1;

				if (chosen == 0) {
					double previous_significance = stance.getSignificance();
					stance.setSignifcance(previous_significance + increment);
					std::cout << " SIGNIFICANCE CHANGED FROM " << previous_significance << " TO " << stance.getSignificance() << std::endl;
				} else {
					double previous_strength = stance.getStrength();
					stance.setStrength(previous_strength + increment);
					std::cout << " STRENGTH CHANGED FROM " << previous_strength << " TO " << stance.getStrength() << std::endl;
				}
			} else if (event > 0.6 && event < 0.8) {
				std::cout << "\t\tIMPACTING LEADER POPULARITY" << std::endl;
				int chosen_party = get_random_int(0, parties.size());
				Party party = parties.at(chosen_party);

				Leader leader = party.getLeader();

				double previous_popularity = leader.getPopularity();

				leader.setPopularity(previous_popularity + get_random(-0.1, 0.1));

				std::cout << "\t\t\tLEADER FOR PARTY " << chosen_party + 1 << " CHANGED POPULARITY FROM " << previous_popularity << " TO " << leader.getPopularity() << std::endl;

			} else {
				std::cout << "\t\tIMPACTING DIVISION STANCE" << std::endl;

				int chosen = get_random_int(0, 2);
				double increment = get_random(-0.1, 0.1);
				Division division = divisions.at(y);
				int chosen_stance = get_random_int(0, division.getStances().size());
				Stance stance = division.getStance(chosen_stance);

				std::cout << "\t\t\tDIVISION " << y + 1 << " STANCE " << chosen_stance + 1;

				if (chosen == 0) {
					double previous_significance = stance.getSignificance();
					stance.setSignifcance(previous_significance + increment);
					std::cout << " SIGNIFICANCE CHANGED FROM " << previous_significance << " TO " << stance.getSignificance() << std::endl;
				} else {
					double previous_strength = stance.getStrength();
					stance.setStrength(previous_strength + increment);
					std::cout << " STRENGTH CHANGED FROM " << previous_strength << " TO " << stance.getStrength() << std::endl;
				}
			}
		}
	}

	// wins array
	int wins[3] = {0, 0, 0};

	// for each division
	for (int i = 0; i < n_divisions; i++) {
		Division division = divisions.at(i);
		int highest_index = 0;
		double highest = 0;
		int highest_party = 0;

		// for each party
		for (int j = 0; j < 3; j++) {
			Party party = parties.at(j);
			Leader leader = party.getLeader();

			// for each candidate
			for (int c = 0; c < party.getCandidates().size(); c++) {
				Candidate candidate = party.getCandidate(c);


				double stanceAndPopulationFactor = calculateStanceAndPopularityFactor(candidate, division);
				// coefficients are 0.55, 0.35 and 0.1
				double score = (0.55*(stanceAndPopulationFactor))+(0.35*(candidate.getPopularity())+(0.1*(leader.getPopularity())));
				// if the calculated score is greater then adjust the sentinel variables
				if (score > highest) {
					highest = score;
					highest_index = c;
					highest_party = j;
				}
			}
		}

		wins[highest_party]++;
	}

	// print the national summary
	std::cout << "\nNATIONAL SUMMARY: " << std::endl;

	// sentinel variables for winning government and hung
	int winner = 0;
	int highest = -1;
	bool hung = false;
	for (int i = 0; i < 3; i++) {
		std::cout << "PARTY " << i + 1 << ":" << std::endl;
		std::cout << "\tWINS = " << wins[i] << std::endl;

		// if the wins are higher, then adjust
		if (wins[i] > highest) {
			highest = wins[i];
			winner = i;
		// else if its the same, then check if its the last one and make hung parliament
		} else if (wins[i] == highest && i == 2) {
			hung = true;
		}

	}

	// if hung, then show the outcome
	if (hung) {
		std::cout << "\nOUTCOME: HUNG PARLIAMENT" << std::endl;
	} else {
		// print the winner
		std::cout << "\nOUTCOME: PARTY " << winner + 1 << " WINS!";
	}
 
	// return 0.
    return 0;
}