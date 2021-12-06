#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include "InfInt.h"

std::string line;
int main() {
	std::ifstream infile("clue.txt");
	std::string line;

	InfInt fish[9];

	for (int i = 0; i < 9; i++) {
		fish[i] = 0;
	}

	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		int f;
		char comma;

		while (iss >> f) {
			iss >> comma;
			fish[f] = fish[f] + 1;
		}
	}

	for (int day = 0; day < 256; day++) {
		InfInt newBorns = fish[0];
		fish[0] = 0;
		for (int i = 1; i < 9; i++) {
			fish[i - 1] = fish[i];
		}

		fish[8] = newBorns;
		fish[6] = fish[6] + newBorns;
	}

	InfInt total = 0;
	for (int i = 0; i < 9; i++) {
		total += fish[i];
	}

	std::cout << total;

}