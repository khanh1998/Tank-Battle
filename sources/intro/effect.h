#define WIDTH 80
#define HIGHT 40

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
            consoleBuffer[above][j].Attributes = BACKGROUND_INTENSITY;
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
            consoleBuffer[bottom][j].Attributes = BACKGROUND_INTENSITY;
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
