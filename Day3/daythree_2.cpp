#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

int main() {
	std::ifstream infile("in.txt");
	std::string line;

	std::vector<std::string> file;
	

	while (std::getline(infile, line)) {
		file.push_back(line);
	}

	std::vector<std::string> oxygen = file;
	std::vector<std::string> co2 = file;

	for (int pos = 0; pos < oxygen[0].length(); pos++) {
		int ones = 0;
		for (int i = 0; i < oxygen.size(); i++) {
			ones += oxygen[i][pos] == '1' ? 1 : 0;
		}

		int zeroes = oxygen.size() - ones;

		if (oxygen.size() > 1) {
			if (ones >= zeroes) {
				oxygen.erase(std::remove_if(oxygen.begin(), oxygen.end(), [pos](std::string i) { return i[pos] == '0'; }), oxygen.end());
			}
			else if (ones < zeroes) {
				oxygen.erase(std::remove_if(oxygen.begin(), oxygen.end(), [pos](std::string i) { return i[pos] == '1'; }), oxygen.end());
			}
		}
		else {
			break;
		}
	}

	for (int pos = 0; pos < co2[0].length(); pos++) {
		int ones = 0;
		for (int i = 0; i < co2.size(); i++) {
			ones += co2[i][pos] == '1' ? 1 : 0;
		}

		int zeroes = co2.size() - ones;

		if (co2.size() > 1) {
			if (ones >= zeroes) {
				co2.erase(std::remove_if(co2.begin(), co2.end(), [pos](std::string i) { return i[pos] == '1'; }), co2.end());
			}
			else if (ones < zeroes) {
				co2.erase(std::remove_if(co2.begin(), co2.end(), [pos](std::string i) { return i[pos] == '0'; }), co2.end());
			}
		}
		else {
			break;
		}
	}

	int o = 0;
	int c = 0;
	for (int i = 0; i < oxygen[0].length(); i++) {
		if (oxygen[0][i] == '1') o += (1 << (oxygen[0].length() - 1 - i));
		if (co2[0][i] == '1') c += (1 << (oxygen[0].length() - 1 - i));
	}
	std::cout << o * c;
}