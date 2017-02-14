#include <windows.h>

#define WIDTH 80
#define HIGHT 40

//BACKGROUND_INTENSITY, BACKGROUND_RED, BACKGROUND_GREEN, FOREGROUND_BLUE
typedef struct{
    int x;
    int y;
}coordinate;


#include "printfLetter.h"
void gotoXY (int* x, int newX, int* y, int newY){
    *x = newX;
    *y = newY;
}

void letter (CHAR_INFO consoleBuffer[HIGHT][WIDTH], coordinate list[], int x, int y, int color){
    int leng = (int)sizeof(consoleBuffer)/sizeof(CHAR_INFO);
    int i;
    for (i = 0; i < leng; i++){
        consoleBuffer[x + list[i].x][y + list[i].y].Attributes = BACKGROUND_RED;
    }
}

void Print_Letter (CHAR_INFO consoleBuffer[HIGHT][WIDTH]){
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
    coordinate listE[17] = { {0,0}, {1,0}, {2,0}, {3,0}, {4,0}, {5,0},
                            {5,1}, {5,2}, {5,3}, {5,4},
                            {2,1}, {2,2}, {2,3},
                            {0,1}, {0,2}, {0,3}, {0,4}
    };
    coordinate listn[12] = {{1,0}, {2,0}, {3,0}, {4,0}, {5,0},
                            {1,1}, {1,2}, {1,3},
                            {2,4}, {3,4}, {4,4}, {5,4}
    };
    coordinate listt[12] = { {0,2}, {1,2}, {2,2}, {3,2}, {4,2}, {5,2},
                            {1,0}, {1,1}, {1,2}, {1,3}, {1,4},
                            {5,3}
    };
    coordinate liste[14] = { {2,0}, {3,0}, {4,0}, {2,4},
                            {1,1}, {1,2}, {1,3}, {3,1}, {3,2}, {3,3}, {5,1}, {5,2}, {5,3}, {5,4}
    };
    coordinate listr[9] = { {1,0}, {2,0}, {3,0}, {4,0}, {5,0},
                            {2,1}, {2,4}, {1,2}, {1,3}
    };
    coordinate greaterSign[14] = { {0,0}, {0,1}, {1,1}, {1,2}, {2,2}, {2,3}, {3,3}, {3,4}, {4,2}, {4,3}, {5,1}, {5,2}, {6,0}, {6,1} };

    WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);

}
