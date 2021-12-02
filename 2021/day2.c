#include <stdio.h>
#include <stdlib.h>

char lineData[6];
int forward = 0;
int up = 0;
int down = 0;

int main() {
    FILE * inputFile = fopen ("./input/day2.txt", "r");

    while (fgets(lineData, 6, inputFile) != NULL) {
        printf("%c\n", lineData[0]);
        if (lineData[0] == u") {

        } else if (lineData[0] == "d") {

        } else if (lineData[0] == "f") {

        }
      
    }
    return 0;

}