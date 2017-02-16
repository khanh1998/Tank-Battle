#include "intro.h"

void intro(CHAR_INFO consoleBuffer[HIGHT][WIDTH]){
    clearScreen(consoleBuffer);
    Print_Letter(consoleBuffer);
    clearScreen(consoleBuffer);
    effect(consoleBuffer);
}
