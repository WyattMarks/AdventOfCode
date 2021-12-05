#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

class Line {
public:
	int x1, y1, x2, y2;
	Line(int x1, int y1, int x2, int y2) {
		this->x1 = x1;
		this->x2 = x2;
		this->y1 = y1;
		this->y2 = y2;
	}

	bool contains(int x, int y) {
		return (x == x1 || y == y1) && ((x >= x1 && x <= x2) || (x >= x2 && x <= x1)) && ((y >= y1 && y <= y2) || (y >= y2 && y <= y1));
	}
};

std::string line;
int main() {
	std::ifstream infile("infile.txt");
	std::string line;

	int maxX = 0, maxY = 0, minY = INT_MAX, minX = INT_MAX;

	std::vector<Line> lines;

	while (std::getline(infile, line)) {
		std::istringstream iss(line);
		int x1, y1, x2, y2;
		std::string arrow;
		char comma;

		iss >> x1;
		iss >> comma;
		iss >> y1;
		iss >> arrow;
		iss >> x2;
		iss >> comma;
		iss >> y2;

		if (x1 == x2 || y1 == y2) {

			if (x1 > maxX) maxX = x1;
			if (x2 > maxX) maxX = x2;
			if (y1 > maxY) maxY = y1;
			if (y2 > maxY) maxY = y2;
			if (x1 < minX) minX = x1;
			if (x2 < minX) minX = x2;
			if (y1 < minY) minY = y1;
			if (y2 < minY) minY = y2;

			Line l(x1, y1, x2, y2);

			lines.push_back(l);
		}
	}

	int twos = 0;

	for (int y = minY; y <= maxY; y++) {
		for (int x = minX; x <= maxX; x++) {
			int hits = 0;
			for (int l = 0; l < lines.size(); l++) {
				if (lines[l].contains(x, y)) {
					hits++;
				}
			}
			//std::cout << hits;

			if (hits >= 2)
				twos++;
		}
		//std::cout << std::endl;
	}

	std::cout << twos;

}