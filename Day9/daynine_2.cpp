#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

int recursiveBasinSize(int x, int y, std::vector<std::vector<int>> &ogGrid, std::vector<std::vector<int>> &markedGrid) {
	if (ogGrid[y][x] < 9 && markedGrid[y][x] > -1) {
		markedGrid[y][x] = -1;

		return 1 + recursiveBasinSize(x + 1, y, ogGrid, markedGrid) + recursiveBasinSize(x - 1, y, ogGrid, markedGrid) + recursiveBasinSize(x, y - 1, ogGrid, markedGrid) + recursiveBasinSize(x, y + 1, ogGrid, markedGrid);
	}

	return 0;
}

bool greaterThan(int x, int y) {
	return x > y;
}

std::string line;
int main() {
	std::ifstream infile("9.txt");
	std::string line;

	std::vector<std::vector<int>> grid;
	bool first = true;
	std::vector<int> firstRow;

	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		std::vector<int> row;
		row.push_back(9); //use a wall of 9's to avoid edge case crap
		char num;
		while (iss >> num) {
			row.push_back(num - '0');
		}
		row.push_back(9);

		if (first) {
			for (int i = 0; i < row.size(); i++) {
				firstRow.push_back(9);
			}

			grid.push_back(firstRow);
			first = false;
		}

		grid.push_back(row);
	}

	std::vector<int> lastRow = firstRow;
	grid.push_back(lastRow);

	std::vector<int> sizes;
	for (int y = 1; y < grid.size() - 1; y++) {
		for (int x = 1; x < grid[0].size() - 1; x++) {
			int n = grid[y][x];
			if (n < grid[y - 1][x] && n < grid[y + 1][x] && n < grid[y][x + 1] && n < grid[y][x - 1]) {
				std::vector<std::vector<int>> markedGrid = grid;
				int s = recursiveBasinSize(x, y, grid, markedGrid);
				sizes.push_back(s);
			}
		}
	}

	std::nth_element(sizes.begin(), sizes.begin() + 2, sizes.end(), greaterThan);
	std::cout << sizes[0] * sizes[1] * sizes[2];
}