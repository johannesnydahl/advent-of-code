#include <iostream>
#include <string>
#include <fstream>

int checkTrees(int steps, int skip) {
	std::string a;
	int k = 0;
	int	p = 0;
	int g = 0;
	int f = 0;

	std::ifstream infile("../input/day3.txt");

	while (infile >> a) {
		std::cout << f << std::endl;

		if (f == 0) {
			std::cout << "Skipped first line" << std::endl;
		}
		else if (f % 2 != 0 && skip == 1) {
			std::cout << "Skipped!" << std::endl;
		}
		else {
			if (g + steps > a.length() - 1) {
				g = g + steps - a.length();
				std::cout << "Position: " << g << std::endl;
			}
			else {
				g += steps;
				std::cout << "Position: " << g << std::endl;
			}
			if (a[g] == '#') {
				p++;
				std::cout << "Tree!" << std::endl;
			}
			else {
				std::cout << "No tree!" << std::endl;

			}
		}
		f++;
	}
	return p;
}

int main() {
	long answer = checkTrees(1, 0) * checkTrees(5, 0) * checkTrees(7, 0) * checkTrees(1, 1);
	std::cout << "Answer: "<< answer << std::endl;
}
	

