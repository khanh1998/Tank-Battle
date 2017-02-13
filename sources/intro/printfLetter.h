typedef struct{
    int x;
    int y;
}coordinate;

void gotoXY (int* x, int newX, int* y, int newY){
    *x = newX;
    *y = newY;
}

void Letter_A (CHAR_INFO consoleBuffer[HIGHT][WIDTH], int x, int y, int color){
    coordinate list[13] = {{0,2}, {1,1}, {1,3}, {2,1}, {2,3}, {3,0}, {3,1}, {3,2}, {3,3}, {3,4}, {4,0}, {4,4}, {5,0}, {5,4}};
    int i;
    for (i = 0; i <= 13; i++){
        consoleBuffer[x + list[i].x][y + list[i].y].Attributes = BACKGROUND_RED;
    }
}
