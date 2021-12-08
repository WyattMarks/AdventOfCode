#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

std::string line;
int main() {
	std::ifstream infile("8.txt");
	std::string line;
	std::vector<std::vector<std::string>> mixedNumbers;
	std::vector<std::vector<std::string>> output;

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
				out.push_back(word);
			}
			else {
				numbers.push_back(word);
			}
		}

		mixedNumbers.push_back(numbers);
		output.push_back(out);
		
	}

	int digits[10];
	for (int i = 0; i < 10; i++)
		digits[i] = 0;

	for (int i = 0; i < output.size(); i++) {

		for (int j = 0; j < output[i].size(); j++) {
			int len = output[i][j].length();
			switch (len) {
				case 2:
					digits[1]++;
					break;
				case 4:
					digits[4]++;
					break;
				case 3: 
					digits[7]++;
					break;
				case 7:
					digits[8]++;
					break;
				default:
					break;
			}
		}

	}

	int total = 0;
	for (int i = 0; i < 10; i++)
		total += digits[i];

	std::cout << total;

}