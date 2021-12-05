#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

class BoardItem {
public:
	bool marked = false;
	int value;

	BoardItem() {}
	BoardItem(int value) {
		this->value = value;
	}
};

class Board {
	public:
		std::vector<std::vector<BoardItem>> grid;
		int score = 0;

		Board() {}
		Board(std::string firstLine) {
			AddLine(firstLine);
		}

		void AddLine(std::string line) {
			std::vector<BoardItem> row;
			grid.push_back(row);

			std::istringstream iss(line);
			int n;

			while (iss >> n) {
				BoardItem item(n);
				grid[grid.size() - 1].push_back(item);
			}
		}

		bool CheckBingo(int lastNumber) {
			for (int row = 0; row < grid.size(); row++) {
				bool h = true;

				for (int col = 0; col < grid[row].size(); col++) {
					h = h && grid[row][col].marked;
				}

				if (h) {
					score = lastNumber;
					return true;
				}
			}

			for (int col = 0; col < grid[0].size(); col++) {
				bool v = true;

				for (int row = 0; row < grid.size(); row++) {
					v = v && grid[row][col].marked;
				}

				if (v) {
					score = lastNumber;
					return true;
				}
			}
		}

		bool MarkNumber(int n) {
			for (int row = 0; row < grid.size(); row++) {
				for (int col = 0; col < grid[row].size(); col++) {
					if (n == grid[row][col].value) {
						grid[row][col].marked = true;
					}
				}
			}

			return CheckBingo(n);
		}

		int CalcScore() {
			int lastNumber = score;
			score = 0;

			for (int row = 0; row < grid.size(); row++) {
				for (int col = 0; col < grid[row].size(); col++) {
					if (!grid[row][col].marked) {
						score += grid[row][col].value;
					}
				}
			}

			score *= lastNumber;
			return score;
		}
};



std::string line;
int main() {
	std::ifstream infile("i.txt");
	std::string line;


	std::vector<int> numbers;
	std::vector<Board> boards;

	bool first = true;
	while (std::getline(infile, line)) {
		
		if (first) {
			std::istringstream iss(line);
			int n;
			char comma;
			while (iss >> n) {
				numbers.push_back(n);
				iss >> comma;
			}
			first = false;
			continue;
		}

		if (line.compare("") == 0) {
			Board b;
			boards.push_back(b);
		}
		else {
			boards[boards.size() - 1].AddLine(line);
		}
	}

	int bingo = -1;

	for (int i = 0; i < numbers.size(); i++) {
		for (int b = 0; b < boards.size(); b++) {
			if (boards[b].MarkNumber(numbers[i])) {
				bingo = b;
				std::cout << b + 1 << " board wins with a score of " << boards[b].CalcScore() << std::endl;
				break;
			}
		}
		if (bingo > -1) break;
	}
}