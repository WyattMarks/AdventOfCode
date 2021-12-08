#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

std::string line;

int overlaps(std::string output, std::string second) {
	int o = 0;
	for (int i = 0; i < second.length(); i++) {
		if (output.find(second[i]) != std::string::npos) {
			o++;
		}
	}
	return o;
}

int main() {
	std::ifstream infile("8.txt");
	std::string line;
	std::vector<std::vector<std::string>> mixedNumbers;
	std::vector<std::vector<std::string>> output;
	std::vector<std::vector<std::string>> mapping;

	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		std::string word;
		bool readingOut = false;
		std::vector<std::string> numbers;
		std::vector<std::string> out;

		while (iss >> word) {
			if (word == "|") {
				readingOut = true;
				continue;
			}
			else if (readingOut) {
				numbers.push_back(word);
				out.push_back(word);
			}
			else {
				numbers.push_back(word);
			}
		}

		mixedNumbers.push_back(numbers);
		output.push_back(out);

	}



	for (int i = 0; i < mixedNumbers.size(); i++) {
		std::vector<std::string> map;
		for (int k = 0; k < 10; k++) { map.push_back(""); }

		while (true) {
			for (int j = 0; j < mixedNumbers[i].size(); j++) {
				int len = mixedNumbers[i][j].length();
				switch (len) {
					case 2:
						map[1] = mixedNumbers[i][j];
						break;
					case 3:
						map[7] = mixedNumbers[i][j];
						break;
					case 4:
						map[4] = mixedNumbers[i][j];
						break;
					case 5:
						//2 or 3 or 5

						if (map[1] == "" || map[4] == "")
							break;

						if (overlaps(mixedNumbers[i][j], map[1]) == 2) { //3
							map[3] = mixedNumbers[i][j];
						}
						else { //2 or 5
							if (overlaps(mixedNumbers[i][j], map[4]) == 2) { // 2
								map[2] = mixedNumbers[i][j];
							}
							else { // 5
								map[5] = mixedNumbers[i][j];
							}
						}
						break;
					case 6:
						//0, 6, 9

						if (map[4] == "" || map[5] == "")
							break;
						if (overlaps(mixedNumbers[i][j], map[4]) == 3) { // 0 or 6
							if (overlaps(mixedNumbers[i][j], map[5]) == 4) { // 0
								map[0] = mixedNumbers[i][j];
							}
							else {
								map[6] = mixedNumbers[i][j];
							}
						}
						else { // 9
							map[9] = mixedNumbers[i][j];
						}
						break;
					case 7:
						map[8] = mixedNumbers[i][j];
						break;
					default:
						break;
				}


			}

			bool done = true;
			for (int i = 0; i < 10; i++) {
				if (map[i] == "")
					done = false;
			}
			if (done)
				break;
		}

		mapping.push_back(map);
	}


	int total = 0;
	std::vector<int> outputs;
	for (int i = 0; i < output.size(); i++) {
		int o = 0;
		for (int d = 0; d < output[i].size(); d++) {
			int value = 0;
			for (int j = 0; j < 10; j++) {
				if (output[i][d].length() == mapping[i][j].length() && overlaps(mapping[i][j], output[i][d]) == output[i][d].length()) {
					value = j;
					break;
				}
			}

			o += value * pow(10, output[i].size() - d - 1);
		}
		outputs.push_back(o);
		total += o;
	}

	std::cout << total;
}