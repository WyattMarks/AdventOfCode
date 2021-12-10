#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::string line;
int main() {
	std::ifstream infile("10.txt");
	std::string line;

	std::vector<std::string> completionStrings;
	std::string illegals = "";

	while (std::getline(infile, line)) {
		std::istringstream iss(line);

		std::stack<char> s;

		char c;
		bool done = false;
		while (iss >> c) {
			switch (c) {
				case '(':
					s.push(c);
					break;
				case '[':
					s.push(c);
					break;
				case '<':
					s.push(c);
					break;
				case '{':
					s.push(c);
					break;
				case ')':
					if (s.top() != '(') {
						done = true;
						illegals += c;
					}
					s.pop();
					break;
				case ']':
					if (s.top() != '[') {
						done = true;
						illegals += c;
					}
					s.pop();
					break;
				case '}':
					if (s.top() != '{') {
						done = true;
						illegals += c;
					}
					s.pop();
					break;
				case '>':
					if (s.top() != '<') {
						done = true;
						illegals += c;
					}
					s.pop();
					break;
				default:
					break;
			}

			if (done)
				break;
		}

		if (!done) {
			std::string needed = "";
			while (!s.empty()) {
				switch (s.top()) {
					case '(':
						needed += ')';
						break;
					case '[':
						needed += ']';
						break;
					case '{':
						needed += '}';
						break;
					case '<':
						needed += '>';
						break;
					default:
						break;
				}
				s.pop();
			}

			completionStrings.push_back(needed);
		}
	}

	std::vector<long long> scores;
	for (int i = 0; i < completionStrings.size(); i++) {
		long long score = 0;
		for (int j = 0; j < completionStrings[i].length(); j++) {
			score *= 5;
			switch (completionStrings[i][j]) {
				case ')':
					score += 1;
					break;
				case ']':
					score += 2;
					break;
				case '}':
					score += 3;
					break;
				case '>':
					score += 4;
					break;
				default:
					break;
			}
		}

		scores.push_back(score);
	}

	std::sort(scores.begin(), scores.end());

	int score = 0;
	for (int i = 0; i < illegals.length(); i++) {
		switch (illegals[i]) {
			case ')':
				score += 3;
				break;
			case ']':
				score += 57;
				break;
			case '}':
				score += 1197;
				break;
			case '>':
				score += 25137;
				break;
			default:
				break;
		}
	}

	std::cout << "Part 1: " << score << std::endl << "Part 2: " << scores[scores.size() / 2];
}