#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


int main() {
    char lineData[1000];
    bool readingDrawnNumbers = true;
    char drawnNumbers[500][3] = {0};
    char bingoBoards[500][5][5][3] = {0};
    int bingoBoardIndex = 0;
    int boardLineIndex = 0;
    int drawnNumbersNumberIndex = 0;
    int boardNumberIndex = 0;

	FILE * inputFile = fopen ("./input/day4.txt", "r");
    while (fgets(lineData, sizeof(lineData), inputFile) != NULL) {
        drawnNumbersNumberIndex = 0;
        if (lineData[0] == '\n') { 
            if (readingDrawnNumbers) {
                readingDrawnNumbers = false;
            } else {
                bingoBoardIndex++;
                boardLineIndex = 0;
            }
        //Read drawn numbers
        } else if (readingDrawnNumbers) {
           int charIndex = 0;
           int lineDataIndex = 0;
           while (lineData[lineDataIndex] != '\n') {
               if (lineData[lineDataIndex] != ',') {
                   drawnNumbers[drawnNumbersNumberIndex][charIndex] = lineData[lineDataIndex];
                   charIndex++;
               } else {
                   if (charIndex == 1) {
                       drawnNumbers[drawnNumbersNumberIndex][1] = '\0';
                   }
                   charIndex = 0;
                   drawnNumbersNumberIndex++;
               }
               lineDataIndex++;
           } 
        //Read boards
        } else { 
            int charIndex = 0;
            int lineDataIndex = 0;
            boardNumberIndex = 0;
            while (lineData[lineDataIndex] != '\0') {
                if (lineData[lineDataIndex] == ' ') {
                    bingoBoards[bingoBoardIndex][boardLineIndex][boardNumberIndex][0] = lineData[lineDataIndex + 1];
                    bingoBoards[bingoBoardIndex][boardLineIndex][boardNumberIndex][1] = '\0';
                } else {
                    bingoBoards[bingoBoardIndex][boardLineIndex][boardNumberIndex][0] = lineData[lineDataIndex];
                    bingoBoards[bingoBoardIndex][boardLineIndex][boardNumberIndex][1] = lineData[lineDataIndex + 1];
                }
                lineDataIndex += 3;
                boardNumberIndex++;
            }
            boardLineIndex++; 
        }
    }
    int amountOfBoards = bingoBoardIndex + 1;
    //Parsing is done.
    bool haveWon = false;
    drawnNumbersNumberIndex = 0;
    boardLineIndex = 0;
    boardNumberIndex = 0;
    int horizontalStreak = 0;
    int verticalStreak[5] = {0};
    int unmarkedBoardSum = 0;

    while (!haveWon) {
        //Mark the boards 
        bingoBoardIndex = 0;
        while (bingoBoardIndex < amountOfBoards) {
            while (boardLineIndex < sizeof(bingoBoards[0]) / sizeof(bingoBoards[0][0])) {
                while (boardNumberIndex < sizeof(bingoBoards[0][0]) / sizeof(bingoBoards[0][0][0])) {
                    if (strncmp(bingoBoards[bingoBoardIndex][boardLineIndex][boardNumberIndex], drawnNumbers[drawnNumbersNumberIndex], 3) == 0) {
                        *bingoBoards[bingoBoardIndex][boardLineIndex][boardNumberIndex] = *"\0\0";
                        horizontalStreak++;
                        verticalStreak[boardNumberIndex]++;
                    } else if (strncmp(bingoBoards[bingoBoardIndex][boardLineIndex][boardNumberIndex],"\0\0\0", 3) == 0) {
                        horizontalStreak++;
                        verticalStreak[boardNumberIndex]++; 
                    } else {
                        unmarkedBoardSum += atoi(bingoBoards[bingoBoardIndex][boardLineIndex][boardNumberIndex]);
                    }
                    boardNumberIndex++;
                }
                if (horizontalStreak == 5 && !haveWon) {
                    haveWon = true;
                }
                boardNumberIndex = 0;
                boardLineIndex++;
                horizontalStreak = 0;
            }
            for (int i = 0; i < 5; i++) {
                if (verticalStreak[i] == 5 && !haveWon) {
                    haveWon = true;
                    break;
                }
            }
            boardLineIndex = 0;
            bingoBoardIndex++;
            for (int i = 0; i < 5; i++) {
                verticalStreak[i] = 0;
            }

            if (haveWon) {
                break;
            }
            unmarkedBoardSum = 0;
        }
        if (haveWon) {
            break;
        }
        drawnNumbersNumberIndex++;
    }
    printf("Part: 1 %i", unmarkedBoardSum * atoi(drawnNumbers[drawnNumbersNumberIndex]));
	return 0;
}