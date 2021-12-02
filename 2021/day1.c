#include <stdio.h>
#include <stdlib.h>

char lineData[6];
int ints[2000];

int main() {
    FILE * inputFile = fopen ("./input/day1.txt", "r");
    int currentLine = 0;
    
    while (fgets(lineData, 6, inputFile) != NULL) {
      ints[currentLine] = atoi(lineData);
      currentLine++;
    }

    int increasedTimes = 0;

    for (int i = 1; i <= currentLine; i++ ) {
        if (ints[i] > ints[i - 1]) {
            increasedTimes++;
        }
    }

    printf("Increased (pt 1): %i\n", increasedTimes);

    increasedTimes = 0;

    for (int i = 3; i <= currentLine; i++ ) {
        if ((ints[i] + ints[i - 1] + ints[i - 2]) > (ints[i -1] + ints[i-2] + ints[i - 3 ])) {
            increasedTimes++;
        }
    }

    printf("Sums increased (pt 2): %i\n", increasedTimes);  
    
    return 0;
}