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
    int amountOfBoardsLeft = amountOfBoards;
    //Parsing is done.
    bool haveWon = false;
    drawnNumbersNumberIndex = 0;
    boardLineIndex = 0;
    boardNumberIndex = 0;
    int horizontalStreak = 0;
    int verticalStreak[5] = {0};
    int unmarkedBoardSum = 0;
    bool markedNumbers[5][5] = {false};
    int streak = 0;
    int boardsThatHaveWon[500] = {0};
    int boardsThatHaveWonLength = 0;
    bool haveAlreadyWon = false;
    bool haveAlreadyFoundOne = false;
    while (amountOfBoardsLeft != 0) {
        //Mark the boards 
        bingoBoardIndex = 0;
        while (bingoBoardIndex < amountOfBoards) {
            for (int i = 0; i < boardsThatHaveWonLength; i++) {
                    if (bingoBoardIndex == boardsThatHaveWon[i]) {
                        haveAlreadyWon = true;
                        break; 
                        }
                    }
                    if (haveAlreadyWon) {
                        haveAlreadyWon = false;
                        bingoBoardIndex++;
                        continue;
                    } 
              
            while (boardLineIndex < sizeof(bingoBoards[0]) / sizeof(bingoBoards[0][0])) {
                while (boardNumberIndex < sizeof(bingoBoards[0][0]) / sizeof(bingoBoards[0][0][0])) {
                    if (strncmp(bingoBoards[bingoBoardIndex][boardLineIndex][boardNumberIndex], drawnNumbers[drawnNumbersNumberIndex], 3) == 0) {
                        *bingoBoards[bingoBoardIndex][boardLineIndex][boardNumberIndex] = *"\0\0";
                        markedNumbers[boardLineIndex][boardNumberIndex] = true;
                    } else if (strncmp(bingoBoards[bingoBoardIndex][boardLineIndex][boardNumberIndex],"\0\0\0", 3) == 0) {
                        markedNumbers[boardLineIndex][boardNumberIndex] = true;
                    } else {
                        unmarkedBoardSum += atoi(bingoBoards[bingoBoardIndex][boardLineIndex][boardNumberIndex]);
                    }
                    boardNumberIndex++;
                }
                boardNumberIndex = 0;
                boardLineIndex++;
            }
                for (int i = 0; i < 5; i++) {
                    for (int a = 0; a < 5; a++) {
                        if (markedNumbers[a][i]) {
                            streak++;
                        }
                    }
                    if (streak == 5 && !haveAlreadyFoundOne) {
                        haveAlreadyFoundOne = true;
                        printf("Part: 2 %i\n", unmarkedBoardSum * atoi(drawnNumbers[drawnNumbersNumberIndex]));
                        amountOfBoardsLeft--;
                        boardsThatHaveWon[boardsThatHaveWonLength] = bingoBoardIndex;
                        boardsThatHaveWonLength++;
                        streak = 0;
                        break;
                    }
                    streak = 0;
                }
                for (int i = 0; i < 5; i++) {
                    for (int a = 0; a < 5; a++) {
                        if (markedNumbers[i][a]) {
                            streak++;
                        }
                    }
                    if (streak == 5 && !haveAlreadyFoundOne) {
                        printf("Part: 2 %i\n", unmarkedBoardSum * atoi(drawnNumbers[drawnNumbersNumberIndex]));
                        haveAlreadyFoundOne = true;
                        amountOfBoardsLeft--;
                        boardsThatHaveWon[boardsThatHaveWonLength] = bingoBoardIndex;
                        boardsThatHaveWonLength++;
                        streak = 0;
                        break;
                    }
                    streak = 0;   
                }
            
            for (int i = 0; i < 5; i++) {
                for (int a = 0; a < 5; a++) {
                    markedNumbers[a][i] = false;
                }
            }
            boardLineIndex = 0;
            bingoBoardIndex++;
            unmarkedBoardSum = 0;
            haveAlreadyFoundOne = false;
        }
        bingoBoardIndex = 0;
        drawnNumbersNumberIndex++;
    }
	return 0;
}