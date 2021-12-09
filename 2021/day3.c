#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

char lineData[14];
int zeroOrOneArray[12];
int gammaRate = 0;
int epsilonRate = 0;
char oxygenArray[1000][13];
char scrubberArray[1000][13];

int main() {
    printf("%i", sizeof(oxygenArray));
    FILE * inputFile = fopen ("./input/day3.txt", "r");
    while (fgets(lineData, 14, inputFile) != NULL) {
        for (int i = 0; i < 14; i++) {
            if (lineData[i] == '0') {
                zeroOrOneArray[i] -= 1;
            } else if (lineData[i] == '1') {
                zeroOrOneArray[i] += 1;
            }
        } 
    }   

    fclose(inputFile);

    for (int i = 0; i < 12; i++) {
        if (zeroOrOneArray[11 - i] > 0 ) {
            gammaRate += pow(2, i);
        } else {
            epsilonRate += pow(2, i);
        }
    }

    printf("Part 1: %i\n", epsilonRate * gammaRate);

    char mostCommonFirstBit = '1';

    if (zeroOrOneArray[0] < 0) {
        mostCommonFirstBit = '0';
    }
    
    int oxygenArraySize = 0;
    int scrubberArraySize = 0;

    inputFile = fopen ("./input/day3.txt", "r");
    int line = 0;
    while (fgets(lineData, 14, inputFile) != NULL) {
        //lineData[5] = 0; 
        lineData[strcspn(lineData, "\n")] = 0;
       // printf("Line data: %s\n", lineData);
        if (lineData[0] == mostCommonFirstBit) {
            strncpy(oxygenArray[oxygenArraySize], lineData, 13);
        //    printf("1: %s\n", oxygenArray[oxygenArraySize]);
            oxygenArraySize++;
        } else if (lineData[0] != mostCommonFirstBit) {
            strncpy(scrubberArray[scrubberArraySize], lineData, 13);
         //   printf("0: %s\n", scrubberArray[scrubberArraySize]);
            scrubberArraySize++;   
        }
            line++;
            printf("Line: %i Content: %s \n", line, lineData);

    }
    /* for (int i = 0; i < 50; i++) {
        printf("Element %i: %s\n", i, scrubberArray[i]);
    }
    for (int i = 0; i < 50; i++) {
        printf("Element %i: %s\n", i, oxygenArray[i]);
    } */

    int currentBitIndex = 1;
    int currentNumber = 0;
    int zeroOrOneInt = 0;  
    
    while(oxygenArraySize != 1) {
    zeroOrOneInt = 0;  
        while (currentNumber < oxygenArraySize) {
            if (oxygenArray[currentNumber][currentBitIndex] == '0') {
                zeroOrOneInt -= 1;
            } else if (oxygenArray[currentNumber][currentBitIndex] == '1') {
                zeroOrOneInt += 1;
            }
            currentNumber++;
        }
        
        mostCommonFirstBit = '1';
        if (zeroOrOneInt < 0) {
            mostCommonFirstBit = '0';
        }  
        currentNumber = 0;


    while (currentNumber < oxygenArraySize && oxygenArraySize != 1) {
            if (oxygenArray[currentNumber][currentBitIndex] != mostCommonFirstBit) {
                for (int i = currentNumber + 1; i < oxygenArraySize; i++) {
                    strcpy(oxygenArray[i - 1], oxygenArray[i]);
                }
                oxygenArraySize--;
                currentNumber--;
            }
             currentNumber++;
            }

    currentBitIndex++;
    currentNumber = 0;
    }

    printf("%s\n", oxygenArray[0]);

    currentBitIndex = 1;
    currentNumber = 0;
    zeroOrOneInt = 0;  
    

    while(scrubberArraySize != 1) {
    zeroOrOneInt = 0;  
        while (currentNumber < scrubberArraySize) {
            if (scrubberArray[currentNumber][currentBitIndex] == '0') {
                zeroOrOneInt -= 1;
            } else if (scrubberArray[currentNumber][currentBitIndex] == '1') {
                zeroOrOneInt += 1;
            }
            currentNumber++;
        }
        
        mostCommonFirstBit = '0';
        if (zeroOrOneInt < 0) {
            mostCommonFirstBit = '1';
        }  
        currentNumber = 0;


        while (currentNumber < scrubberArraySize && scrubberArraySize != 1) {
            if (scrubberArray[currentNumber][currentBitIndex] != mostCommonFirstBit) {
                //Delete element
                for (int i = currentNumber + 1; i < scrubberArraySize; i++) {
                    strcpy(scrubberArray[i - 1], scrubberArray[i]);
                }
                scrubberArraySize--;
                currentNumber--;
            }
            currentNumber++;
            }

    currentBitIndex++;
    currentNumber = 0;
    }
    printf("ScrubberArray: %s, Oxygenarray: %s\n", scrubberArray[0], oxygenArray[0]);
    printf("Scrubber: %i Oxygen: %i\n", strtol(scrubberArray[0], NULL, 2), strtol(oxygenArray[0], NULL, 2));
    printf("Part 2: %i", strtol(scrubberArray[0], NULL, 2) * strtol(oxygenArray[0], NULL, 2));

	return 0;
}