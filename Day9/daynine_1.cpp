#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

std::string line;
int main() {
	std::ifstream infile("9.txt");
	std::string line;

	std::vector<std::vector<char>> grid;
	bool first = true;
	std::vector<char> firstRow;

	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		std::vector<char> row;
		row.push_back('A');
		char num;
		while (iss >> num) {
			row.push_back(num);
		}
		row.push_back('A');

		if (first) {
			for (int i = 0; i < row.size(); i++) {
				firstRow.push_back('A');
			}

			grid.push_back(firstRow);
			first = false;
		}

		grid.push_back(row);
	}

	std::vector<char> lastRow = firstRow;
	grid.push_back(lastRow);

	int total = 0;
	for (int y = 1; y < grid.size() - 1; y++) {
		for (int x = 1; x < grid[0].size() - 1; x++) {
			char n = grid[y][x];
			if (n < grid[y - 1][x] && n < grid[y + 1][x] && n < grid[y][x + 1] && n < grid[y][x - 1]) {
				int v = n - '0';
				total += v + 1;
			}
		}
	}

	std::cout << total;
}