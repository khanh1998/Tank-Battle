#include <windows.h>
#include <time.h>
#include "sources/intro/intro.h"
#include "sources/init/init.h"

#define WIDTH 80
#define HIGHT 40

int numOfTank = 5;
info tank[10];
info bulets[200];
int tankPositive[39][79];
int play = 1;

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

    while (play){
        // intro the game
        intro(consoleBuffer);
        // init game
        init(consoleBuffer, tank, numOfTank);
        // game loop



        COORD charBufSize = {WIDTH, HIGHT};
        COORD charPos = {0, 0};
        SMALL_RECT writeArea = {0, 0, WIDTH - 1, HIGHT - 1};
        WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);
        getchar();
        //Sleep(100000);
    }
    

    return 0;
}
