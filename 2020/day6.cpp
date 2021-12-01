#include <fstream>
#include <iostream>
#include <string>


std::string input;
int e[26] = { 0 };
int sum = 0;
int members = 0;

int main() {
	std::ifstream file("../input/day6.txt");
	while (getline(file, input)) {
		std::cout << input << std::endl;
		std::cout << input.size() << std::endl;
		if (input.size() != 0) {
			for (int i = 97; i < 123; i++) {
				if (input.find(char(i)) != std::string::npos) {
					e[i - 97]++;

				}


			}
			members++;
		}
		else if (input.size() == 0) {
			std::cout << "#" << std::endl;
			for (int f = 0; f < sizeof(e) / sizeof(*e); f++) {
				if (e[f] == members) {
					sum++;
				}

			}

			members = 0;
			for (int y = 0; y < 26; y++) {
				e[y] = 0;
			}

		}

	}
	std::cout << sum << std::endl;
}