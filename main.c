#include <windows.h>
#include <stdio.h>
typedef struct{
    int x;
    int y;
}coordinate;

#include "sources/intro/intro.h"
#include "sources/intro/effect.h"
#include "sources/intro/printfLetter.h"

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

int main(int argc, char const * argv[]){
    // init console screen
    HANDLE rhnd = GetStdHandle(STD_INPUT_HANDLE);
    HANDLE whnd = GetStdHandle(STD_OUTPUT_HANDLE);
    //set window
    SetConsoleTitle(TEXT("TANK BATTLE"));
    SMALL_RECT windowSize = {0, 0, WIDTH -1, HIGHT -1};
    SetConsoleWindowInfo(whnd, TRUE, &windowSize);
    //set buffer size
    COORD bufferSize = {WIDTH, HIGHT};
    SetConsoleScreenBufferSize(whnd, bufferSize);
    //hide curso
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(whnd, &info);
    //array of console buffer
    CHAR_INFO consoleBuffer[HIGHT][WIDTH];

    // init game
    //init_game();
    clearScreen(consoleBuffer);
    Letter_A(consoleBuffer, 10, 10, 4);
    getchar();
    clearScreen(consoleBuffer);
    effect(consoleBuffer);
    clearScreen(consoleBuffer);
    chuyendong(consoleBuffer);

    /*COORD charBufSize = {WIDTH, HIGHT};
    COORD charPos = {0, 0};
    SMALL_RECT writeArea = {0, 0, WIDTH - 1, HIGHT - 1};
    WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea); */

    return 0;
}
