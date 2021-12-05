#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

std::string line;
int dayone() {
	std::ifstream infile("input.txt");
	std::string line;
	int i = 0;


	int increases = 0;

	int first = -1;
	int second = -1;
	int third = -1;

	int previous = -1;

	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		int num;
		iss >> num;


		if (first > -1 && second > -1 && third > -1) {
			first = second;
			second = third;
			third = num;

			int newSum = first + second + third;
			if (newSum > previous) {
				increases++;
			}

			previous = newSum;
		}
		else {
			if (first == -1) {
				first = num;
			}
			else if (second == -1) {
				second = num;
			}
			else {
				third = num;

				previous = first + second + third;
			}
		}

		
		i++;
	}

	std::cout << increases;

	return 0;
}