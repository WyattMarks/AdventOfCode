#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

std::string line;
int main() {
	std::ifstream infile("clue.txt");
	std::string line;

	std::vector<int> fish;

	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		int f;
		char comma;

		while (iss >> f) {
			iss >> comma;
			fish.push_back(f);
		}
	}

	for (int day = 0; day < 80; day++) {

		for (int i = 0; i < fish.size(); i++) {
			fish[i] = fish[i] - 1;
			if (fish[i] == -1) {
				fish.push_back(9);
				fish[i] = 6;
			}
		}
	}

	std::cout << fish.size();

}