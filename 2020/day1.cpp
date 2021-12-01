#include <iostream>
#include <fstream>
#include <vector>

int main() {
    int a;
    int b;
    int x;
    std::vector<int> v;
    std::ifstream infile("../input/day1.txt");
    while (infile >> a) {
        v.push_back(a);
    }

    std::cout << "Part 1 or 2?";
    std::cin >> x;

    if (x == 1) {
        for (int i = 0; i < v.size(); i++) {
            for (int k = 0; k < v.size(); k++) {
              if (v[i] + v[k] == 2020) {
                std::cout << "Value 1: " << v[i] << std::endl << "Value 2: " << v[k] <<  std::endl << "Product: " << v[i] * v[k]; 
                 goto End;  
             }
        }
        }

    } else {
    
    for (int i = 0; i < v.size(); i++) {
        for (int k = 0; k < v.size(); k++) {
              for (int l = 0; l < v.size(); l++) {
                if (v[i] + v[k] + v[l] == 2020) {
                  std::cout << "Value 1: " << v[i] << std::endl << "Value 2: " << v[k] << std::endl << "Value 3: " << v[l] <<  std::endl << "Product: " << v[i] * v[k] * v[l]; 
                 goto End;    
              }
            
            }

        }
    }
}
    End:  
    return 0;
}