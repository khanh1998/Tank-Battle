#include <windows.h>
#include "printfLetter.h"
#define WIDTH 80
#define HIGHT 40

typedef struct{
    int x;
    int y;
}coordinate;

void gotoXY (int* x, int newX, int* y, int newY){
    *x = newX;
    *y = newY;
}

void Letter_A (CHAR_INFO consoleBuffer[HIGHT][WIDTH], int x, int y, int color){
    HANDLE whnd = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD charBufSize = {WIDTH, HIGHT};
    COORD charPos = {0, 0};
    SMALL_RECT writeArea = {0, 0, WIDTH - 1, HIGHT - 1};
    coordinate listA[14] = {{0,2}, {1,1}, {1,3}, {2,1}, {2,3}, {3,0},
                            {3,1}, {3,2}, {3,3}, {3,4}, {4,0}, {4,4}, {5,0}, {5,4}
    };
    coordinate listT[10] = {{0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {1,2}, {2,2}, {3,2}, {4,2}, {5,2}
    };
    coordinate listN[18] = {{0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0},
                            {0,4}, {1,4}, {2,4}, {3,4}, {4,4}, {5,4},
                            {0,1},{1,1}, {2,2}, {3,2}, {4,3}, {5,3}
    };
    coordinate listK[13] = { {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0},
                            {0,4}, {1,3}, {2,2}, {3,1},
                            {5,4}, {4,3}, {3,2}
    };
    coordinate listB[17] = { {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0},
                            {0,1}, {0,2}, {2,1}, {2,2}, {2,3}, {5,1}, {5,2}, {5,3},
                            {1,3}, {4,4}, {3,4}
    };
    coordinate listL[10] = { {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0},
    {5,1}, {5,2}, {5,3}, {5,4}
    };
    coordinate listE[] = { {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0},
    {5,1}, {5,2}, {5,3}, {5,4},
    {2,1}, {2,2}, {2,3},
    {0,1}, {0,2}, {0,3}, {0,4}
    };
    int i;
    for (i = 0; i <= 16; i++){
        consoleBuffer[x + listE[i].x][y + listE[i].y].Attributes = BACKGROUND_RED;
    }
    WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);

}
