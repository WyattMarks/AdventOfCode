#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

std::string line;
int main() {
	std::ifstream infile("inputt.txt");
	std::string line;
	int x = 0, y = 0, aim = 0;

	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		std::string word;
		iss >> word;
		int val;
		iss >> val;
		if (word == ("forward")) {
			x += val;
			y += aim * val;
		}
		else if (word == "down") {
			aim += val;
		}
		else if (word == "up") {
			aim -= val;
		}
	}

	std::cout << x * y;
}