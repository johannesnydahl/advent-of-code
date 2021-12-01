#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::string input;
std::string inputa[594] = { };
std::vector <std::string> direct = {};
int c = 0;
int sum = 0;
int sumb = 0;
int main() {
	std::ifstream file("day7.txt");
	//Load input to array
	while (getline(file, input)) {
		inputa[c] = input;
		c++;

	}

	//Lägga alla väskor som direkt kan ha shiny i array och deltea dom som inte kan ha
	for (int k = 0; k < 594; k++) {
		if (inputa[k].find("shiny gold") != std::string::npos) {
			direct.push_back(inputa[k].substr(0, inputa[k].find("contain") - 2));
			sum++;
			inputa[k] = {};

		}
	}
	while (sum != sumb) {
		sumb = sum;
		for (unsigned int i = 0; i < direct.size(); i++) {
			for (int r = 0; r < sizeof(inputa) / sizeof(*inputa); r++) {
				if (inputa[r].find(direct[i]) != std::string::npos) {
					sum++;
					direct.push_back(inputa[r].substr(0, inputa[r].find("contain") - 2));
					inputa[r] = {};
				}


			}
		}
	}

	std::cout << sum - 1;
	return 0;
}