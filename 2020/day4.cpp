#include <iostream>
#include <string>
#include <fstream>
#include <regex>

//Regex
std::regex hcl ("hcl:#([0-9a-f]){6}");
std::regex byr("(byr:19([2-9])([0-9]))|(byr:200([0-2]))");
std::regex hgt("(hgt:1(((([5-8][0-9])|(9[0-3]))cm)))|(hgt:((59in)|(6[0-9]in)|(7[0-6]in)))");
std::regex iyr("(iyr:201([0-9]))|(iyr:2020)");
std::regex pid("pid:([0-9]){9} ");
std::regex eyr("eyr:20(([2][0-9])|(30))");
std::regex ecl("ecl:(amb|blu|brn|gry|grn|hzl|oth)");


std::string input;
std::string thing;
int i = 0;
int lines = 0;
int a = 0;
int f = 1;
int t = 0;
int main() {
	std::ifstream file("../input/day4.txt");
	//count passports
	while (getline(file, thing)) {
		if (thing.size() == 0) {
			f++;
		}
	}
	std::ifstream filee("../input/day4.txt");
	


	std::string* fullinput = new std::string[f + 1]{ };
	while (getline(filee, input)) {
		if (input.size() > 0) {
			fullinput[i] += input + " ";
		}
		else {
			i++;
		}
	}
	std::string* correctPass = new std::string[206]{ };
	for (int k = 0; k < f; k++) {
		if (fullinput[k].find("byr") != std::string::npos && fullinput[k].find("iyr") != std::string::npos && fullinput[k].find("eyr") != std::string::npos && fullinput[k].find("hgt") != std::string::npos && fullinput[k].find("hcl") != std::string::npos && fullinput[k].find("ecl") != std::string::npos && fullinput[k].find("pid") != std::string::npos) {
			correctPass[a] = fullinput[k];
			a++;
		}

	}


	std::cout << "Correct passports for part 1: " << a << std::endl;
	
	for (int b = 0; b < a; b++) {
		if(std::regex_search(correctPass[b], ecl) && std::regex_search(correctPass[b], byr) && std::regex_search(correctPass[b], iyr) && std::regex_search(correctPass[b], eyr) && std::regex_search(correctPass[b], hgt) && std::regex_search(correctPass[b], hcl) && std::regex_search(correctPass[b], pid)) {
			t++;
		}
	}
	std::cout << "Correct passports for part 2: " << t << std::endl;
	return 0;
}

