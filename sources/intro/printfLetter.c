#include "printfLetter.h"

//NUMBER OF COLOR
//BACKGROUND_INTENSITY 128
//BACKGROUND_RED 64
//BLACK 4
//BACKGROUND_GREEN 32
//FOREGROUND_BLUE 1



void gotoXY (int* x, int newX, int* y, int newY){
    *x = newX;
    *y = newY;
}

void letter (CHAR_INFO consoleBuffer[HIGHT][WIDTH], coordinate list[], int leng, int x, int y, int color){
    //int leng = sizeof(list)/sizeof(list[0]);
    int i;
    for (i = 0; i < leng; i++){
        consoleBuffer[x + list[i].x][y + list[i].y].Attributes = color;
    }
}

void Print_Letter (CHAR_INFO consoleBuffer[HIGHT][WIDTH]){
    HANDLE whnd = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE rhnd = GetStdHandle(STD_INPUT_HANDLE);
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
    // varible for line 1
    coordinate line1 = {6, 9};
    const int widthOfLetter = 5;
    const int space = 1;
    int colorOfletter[10] = {64, 4, 4, 4, 4, 4, 4, 4, 4, 4};
    int i = 0, tmp, forward = 1, charactor;

    // varible for line 2
    coordinate line2 = {21, 19};
    int color1 = 1, color2 = 32;

    DWORD j;
    DWORD numEvents = 0;
    DWORD numEventRead = 0;
    int appRuning = 1;

    while (appRuning){

    //LINE 1 -----------------------------------------------------------------------------------------
    line1.x = 6;
    line1.y = 9;
    clearScreen(consoleBuffer);
    //TANK
    letter(consoleBuffer, listT, 10, line1.x, line1.y+(widthOfLetter+space)*0, colorOfletter[0]);
    letter(consoleBuffer, listA, 14, line1.x, line1.y+(widthOfLetter+space)*1, colorOfletter[1]);
    letter(consoleBuffer, listN, 18, line1.x, line1.y+(widthOfLetter+space)*2, colorOfletter[2]);
    letter(consoleBuffer, listK, 13, line1.x, line1.y+(widthOfLetter+space)*3, colorOfletter[3]);
    //BATTLE
    line1.y = line1.y + (widthOfLetter+space)*3 + 5*2;
    letter(consoleBuffer, listB, 17, line1.x, line1.y+(widthOfLetter+space)*0, colorOfletter[4]);
    letter(consoleBuffer, listA, 14, line1.x, line1.y+(widthOfLetter+space)*1, colorOfletter[5]);
    letter(consoleBuffer, listT, 10, line1.x, line1.y+(widthOfLetter+space)*2, colorOfletter[6]);
    letter(consoleBuffer, listT, 10, line1.x, line1.y+(widthOfLetter+space)*3, colorOfletter[7]);
    letter(consoleBuffer, listL, 10, line1.x, line1.y+(widthOfLetter+space)*4, colorOfletter[8]);
    letter(consoleBuffer, listE, 17, line1.x, line1.y+(widthOfLetter+space)*5, colorOfletter[9]);
    if (forward){
        if (i != 9){
            tmp = colorOfletter[i];
            colorOfletter[i] = colorOfletter[i+1];
            colorOfletter[i+1] = tmp;
            i++;
        }
        else if (i == 9){
            forward = 0;
        }
    }
    if (!forward){
        if (i != 0){
            tmp = colorOfletter[i];
            colorOfletter[i] = colorOfletter[i-1];
            colorOfletter[i-1] = tmp;
            i--;
        }
        else if (i == 0){
            forward = 1;
        }
    }

    //LINE 2---------------------------------------------------------------------------------------------
    line2.x = 21;
    line2.y = 19;
    //Enter
    letter(consoleBuffer, listE, 17, line2.x, line2.y+(widthOfLetter+space)*0, color1);
    letter(consoleBuffer, listn, 12, line2.x, line2.y+(widthOfLetter+space)*1, color1);
    letter(consoleBuffer, listt, 12, line2.x, line2.y+(widthOfLetter+space)*2, color1);
    letter(consoleBuffer, liste, 14, line2.x, line2.y+(widthOfLetter+space)*3, color1);
    letter(consoleBuffer, listr, 9 , line2.x, line2.y+(widthOfLetter+space)*4, color1);

    // >
    letter(consoleBuffer, greaterSign, 14, line2.x, line2.y+(widthOfLetter+space)*5, color2);

    tmp = color1;
    color1 = color2;
    color2 = tmp;


    //OUTPUT-----------------------------------------------------------------------------------------------
    WriteConsoleOutputA(whnd, consoleBuffer, charBufSize, charPos, &writeArea);

    //READ INPUT -----------------------------------------------------------------------------------------
    if(GetAsyncKeyState(VK_RETURN)){
        appRuning = 0;
        break;
    }
    //SLEEP
    Sleep(100);
    }

}
