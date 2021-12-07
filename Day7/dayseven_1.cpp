#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

std::string line;
int main() {
	std::ifstream infile("7.txt");
	std::string line;
	std::vector<int> pos;
	std::vector<int> cost;
	int max = 0;
	int min = INT_MAX;

	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		std::string word;
		int x;
		char comma;

		while (iss >> x) {
			iss >> comma;

			pos.push_back(x);
			if (x > max)
				max = x;
			if (x < min)
				min = x;
		}
	}

	int minCost = min;
	for (int i = min; i <= max; i++) {
		cost.push_back(0);

		for (int j = 0; j < pos.size(); j++) {
			cost[i] += abs(i - pos[j]);
		}

		if (cost[i] < cost[minCost]) {
			minCost = i;
		}
	}

	std::cout << minCost << " " << cost[minCost];
}