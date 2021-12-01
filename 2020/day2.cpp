#include <iostream>
#include <fstream>
#include <string>
#include <sstream> 

int main() {
    int a;
    int b = 0;
    int x = 0;
    std::string f, s, k;
    int range, range2;

    std::ifstream infile("../input/day2.txt");
    while (infile >> f >> k >> s) {
        std::string pref = f.substr(0, f.find("-"));
        f.erase(0, f.find("-") + 1);

        std::stringstream toint(pref);
        std::stringstream toint2(f);
        toint >> range;
        toint2 >> range2;


        a = std::count(s.begin(), s.end(), k[0]);

        if ((a >= range) && (a <= range2)) b++;
        if (s[range - 1] == k[0] ^ s[range2 - 1] == k[0]) x++;

     }
    std::cout << b++ << " passwords were correct for part 1!" << std::endl;
    std::cout << x++ << " passwords were correct for part 2!" << std::endl;
    return 0;
}