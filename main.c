#include <stdio.h>
#include <windows.h>
#include "sources/intro/intro.h"
#include "sources/intro/printfLetter.h"

#include <time.h>
#define WIDTH 80
#define HIGHT 40

enum direction {
    TOP, RIGHT, DOWN, LEFT
};

typedef struct {
    enum direction direc;
    int line;
    int column;
} info;

info tanks[10];
info bulets[200];
int tankPositive[39][79];

void clearScreen(CHAR_INFO consoleBuffer[HIGHT][WIDTH]);
void chuyendong (CHAR_INFO consoleBuffer[HIGHT][WIDTH]);
void tank (CHAR_INFO consoleBuffer[HIGHT][WIDTH], int dong, int cot);
void effect(CHAR_INFO consoleBuffer[HIGHT][WIDTH]);

int main(int argc, char const * argv[]){
    // init console screen
    HANDLE rhnd = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE whnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitle(TEXT("TANK BATTLE"));
    SMALL_RECT windowSize = {0, 0, WIDTH -1, HIGHT -1};
    SetConsoleWindowInfo(whnd, TRUE, &windowSize);
    COORD bufferSize = {WIDTH, HIGHT};
    SetConsoleScreenBufferSize(whnd, bufferSize);
    CHAR_INFO consoleBuffer[HIGHT][WIDTH];

    // init game
    //init_game();
    clearScreen(consoleBuffer);
    effect(consoleBuffer);
    getchar();

    chuyendong(consoleBuffer);

    COORD charBufSize = {WIDTH, HIGHT};
    COORD charPos = {0, 0};
    SMALL_RECT writeArea = {0, 0, WIDTH - 1, HIGHT - 1};
    WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);

    return 0;
}
/*
void effect(CHAR_INFO consoleBuffer[HIGHT][WIDTH]){
    int i = 0; // line
    int j = 0; // column
    int left = 0, right = 79, bottom = 39, above = 0;
    int timeDelay = 100;

    HANDLE whnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD charBufSize = {WIDTH, HIGHT};
    COORD charPos = {0, 0};
    SMALL_RECT writeArea = {0, 0, WIDTH - 1, HIGHT - 1};

    while (!(above > bottom || left > right)){
        //draw above line
        for (j = left; j <= right; j++){
            consoleBuffer[above][j].Attributes = BACKGROUND_RED;
        }
        WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);
        Sleep(timeDelay);
        above++;
        //draw right line
        for (i = above; i <= bottom; i++){
            consoleBuffer[i][right].Attributes = BACKGROUND_RED;
            consoleBuffer[i][right - 1].Attributes = BACKGROUND_RED;
        }
        WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);
        Sleep(timeDelay);
        right -= 2;
        //draw bottom line
        for (j = left; j <= right; j++){
            consoleBuffer[bottom][j].Attributes = BACKGROUND_RED;
        }
        WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);
        Sleep(timeDelay);
        bottom -= 1;
        //draw left line
        for (i = above; i <= bottom; i++){
            consoleBuffer[i][left].Attributes = BACKGROUND_RED;
            consoleBuffer[i][left + 1].Attributes = BACKGROUND_RED;
        }
        WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);
        Sleep(timeDelay);
        left += 2;
    }

}
*/
void tank (CHAR_INFO consoleBuffer[HIGHT][WIDTH], int dong, int cot){
    return;
}

void chuyendong (CHAR_INFO consoleBuffer[HIGHT][WIDTH]){
    //init
    consoleBuffer[0][0].Char.AsciiChar = '.';
    int dong = 0, cot = 0;
    char c = 254;
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
    while (1){
        clock_t now = clock();
        clock_t diffTime = difftime(now, lastUpdateTime);
        if (diffTime >= TICKS){
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
        lastUpdateTime = now;
        }
        consoleBuffer[dong][cot].Char.AsciiChar = c;
        consoleBuffer[dong][cot].Attributes = BACKGROUND_INTENSITY;
        WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);
        sleepTime = TICKS - diffTime;
        if (sleepTime < 0)
            sleepTime = 0;
        Sleep(sleepTime);
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
