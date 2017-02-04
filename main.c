#include <stdio.h>
#include <windows.h>
#define WIDTH 81
#define HIGHT 38

void clearScreen(CHAR_INFO (*consoleBuffer)[]);

int main(int argc, char const * argv[]){
    HANDLE whnd = GetStdHandle(STD_OUTPUT_HANDLE);
    //HANDLE rhnd = GetStdHandle(STD_INPUT_HANDLE);

    SetConsoleTitle(TEXT("TANK BATTLE"));

    SMALL_RECT windowSize = {0, 0, WIDTH -1, HIGHT -1};
    SetConsoleWindowInfo(whnd, TRUE, &windowSize);

    COORD bufferSize = {WIDTH, HIGHT};
    SetConsoleScreenBufferSize(whnd, bufferSize);

    CHAR_INFO consoleBuffer[HIGHT][WIDTH];

    clearScreen(consoleBuffer);

    COORD charBufSize = {WIDTH, HIGHT};
    COORD charPos = {0, 0};
    SMALL_RECT writeArea = {0, 0, WIDTH - 1, HIGHT - 1};

    WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);



    return 0;
}

void clearScreen(CHAR_INFO (*consoleBuffer)[]){
    int i, j;
    for (i = 0; i < HIGHT; i++){
        for (j = 0; j < WIDTH; j++){
            (*((*consoleBuffer + j) + i)).Char.AsciiChar = '-';
            //(*((*consoleBuffer + j) + i )).Attributes =
            //    BACKGROUND_BLUE | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY | FOREGROUND_BLUE;
        }
    }
}
