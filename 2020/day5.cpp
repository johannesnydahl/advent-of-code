#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>  



int rc = 0;
int v = 0;
std::string input;
int u = 0;
int ve[807] = { };

int main() {
	std::ifstream file("../input/day5.txt");
	while (getline(file, input)) {
		//Row	
		float r = 127.0;
		float r2 = 0;
		for (int i = 0; i < 7; i++) {
			if (input[i] == 'F') {
				r = floor((r + r2) / 2);
				v = 1;
			}
			else {
				r2 = ceil((r + r2) / 2);
				v = 0;

			}
		}
		if (v == 1) {
			r = r * 8;
		}
		else {
			r = r2 * 8;
		}


		//Column
		float c = 7.0;
		float c2 = 0;
		for (int f = 7; f < 10; f++) {
			if (input[f] == 'L') {
				c = floor((c + c2) / 2);
				v = 1;
			}
			else {
				c2 = ceil((c + c2) / 2);
				v = 0;
			}
			}
			if (v == 0) {
				c = c2;
				
			}

			if (r + c > rc) {
				rc = r + c;
			}
			ve[u] = r + c;
			//std::cout << r + c << std::endl;
			u++;
		}
	int n = sizeof(ve) / sizeof(ve[0]);

	std::sort(ve, ve + n);
	for (int g = 0; g < 807; g++) {
		if (ve[g] != g + 6) {
			std::cout << g +6 << "Bg" << std::endl;
		}
	}
	for (int x = 0; x < 807; x++) {
		std::cout << ve[x] << std::endl;
	}
	return 0;
	}
	

	
	
	
	

