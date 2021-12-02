#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char lineData[11];
int forward = 0;
int depth = 0;
int currentNumber = 0;
int aim = 0;

int main() {
    FILE * inputFile = fopen("./input/day2.txt", "r");

    while (fgets(lineData, 11, inputFile) != NULL) {
        currentNumber = atoi(&lineData[strcspn(lineData, "\n") - 1]);        
        if (lineData[0] == 'u') {
            depth -= currentNumber;
        } else if (lineData[0] == 'd') {
            depth += currentNumber;
        } else if (lineData[0] == 'f') {
            forward += currentNumber;
        }
      
    }

    printf("Part 1: %i\n", depth*forward);

    depth = 0;  
    forward = 0; 

    fclose(inputFile);
    inputFile = fopen("./input/day2.txt", "r");

    while (fgets(lineData, 11, inputFile) != NULL) {
        currentNumber = atoi(&lineData[strcspn(lineData, "\n") - 1]);        
        if (lineData[0] == 'u') {
            aim -= currentNumber;
        } else if (lineData[0] == 'd') {
            aim += currentNumber;
        } else if (lineData[0] == 'f') {
            forward += currentNumber;
            depth += aim * currentNumber;
        }

    }

    printf("Part 2: %i\n", depth*forward);
    return 0;
}