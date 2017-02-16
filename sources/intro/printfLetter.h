#include <windows.h>
#include "effect.h"
#define WIDTH 80
#define HIGHT 40

typedef struct{
    int x;
    int y;
}coordinate;

void gotoXY (int* x, int newX, int* y, int newY);
void Print_Letter (CHAR_INFO consoleBuffer[HIGHT][WIDTH]);
void letter (CHAR_INFO consoleBuffer[HIGHT][WIDTH], coordinate list[], int leng, int x, int y, int color);



