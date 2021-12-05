#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>


std::string line;
int main() {
	std::ifstream infile("in.txt");
	std::string line;

	std::vector<int> ones;
	int i = 0;
	int lines = 0;


	while (std::getline(infile, line)) {

		for (int i = 0; i < line.length(); i++) {
			if (lines == 0)
				ones.push_back(0);
			ones[i] += line[i] == '1' ? 1 : 0;
		}

		lines++;
	}

	unsigned int gamma = 0;
	unsigned int epsilon = 0;

	for (int i = 0; i < ones.size(); i++) {
		if (ones[i] > lines / 2) {
			gamma += (1 << (ones.size() - 1 - i));
		}
		else {
			epsilon += (1 << (ones.size() - 1 - i));
		}
	}


	std::cout << gamma * epsilon;
}