#include <windows.h>
#include <time.h>
#include <stdio.h>
#include "effect.h"
#define WIDTH 80
#define HIGHT 40


void effect(CHAR_INFO consoleBuffer[HIGHT][WIDTH]){
    int i = 0; // line
    int j = 0; // column
    int left = 0, right = 79, bottom = 39, above = 0;
    int timeDelay = 10;

    HANDLE whnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD charBufSize = {WIDTH, HIGHT};
    COORD charPos = {0, 0};
    SMALL_RECT writeArea = {0, 0, WIDTH - 1, HIGHT - 1};

    while (!(above > bottom || left > right)){
        //draw above line
        for (j = left; j <= right; j++){
            consoleBuffer[above][j].Attributes = BACKGROUND_INTENSITY;
        }
        //WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);
        Sleep(timeDelay);
        above++;
        //draw right line
        for (i = above; i <= bottom; i++){
            consoleBuffer[i][right].Attributes = BACKGROUND_INTENSITY;
            consoleBuffer[i][right - 1].Attributes = BACKGROUND_INTENSITY;
        }
        //WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);
        Sleep(timeDelay);
        right -= 2;
        //draw bottom line
        for (j = left; j <= right; j++){
            consoleBuffer[bottom][j].Attributes = BACKGROUND_INTENSITY;
        }
        //WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);
        Sleep(timeDelay);
        bottom -= 1;
        //draw left line
        for (i = above; i <= bottom; i++){
            consoleBuffer[i][left].Attributes = BACKGROUND_INTENSITY;
            consoleBuffer[i][left + 1].Attributes = BACKGROUND_INTENSITY;
        }
        WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);
        Sleep(timeDelay);
        left += 2;
    }

}

void clearScreen(CHAR_INFO consoleBuffer[HIGHT][WIDTH]){
    int i, j;
    for (i = 0; i < HIGHT; i++){
        for (j = 0; j < WIDTH; j++){
            consoleBuffer[i][j].Char.AsciiChar = ' ';
            consoleBuffer[i][j].Attributes =
                BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY | FOREGROUND_BLUE;
        }
    }
}

void chuyendong (CHAR_INFO consoleBuffer[HIGHT][WIDTH]){
    //init
    int dong = 0, cot = 0;
    HANDLE whnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD charBufSize = {WIDTH, HIGHT};
    COORD charPos = {0, 0};
    SMALL_RECT writeArea = {0, 0, WIDTH - 1, HIGHT - 1};

    clock_t lastUpdateTime = 0;
    clock_t sleepTime;
    int FPS = 60;
    int TICKS = 1000/FPS;
    int i;
    //loop
    while(1){
        clock_t start = clock();
        //clock_t diffTime = difftime(now, lastUpdateTime);
            if (dong == 0 && cot < WIDTH - 1){
                clearScreen(consoleBuffer);
                cot++;
            }
            else if (dong < (HIGHT - 1) && cot == (WIDTH - 1)){
                clearScreen(consoleBuffer);
                dong++;
            }
            else if (dong == (HIGHT - 1) && cot > 0){
                clearScreen(consoleBuffer);
                cot--;
            }
            else if (cot == 0 && dong > 0){
                clearScreen(consoleBuffer);
                dong--;
            }

        consoleBuffer[dong][cot].Attributes = BACKGROUND_INTENSITY;
        WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);
        clock_t now = clock();
        sleepTime = TICKS - (now - start);
        Sleep(sleepTime);
    }
}


