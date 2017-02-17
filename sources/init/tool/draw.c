typedef enum direction Direc;
enum direction {
    TOP, RIGHT, DOWN, LEFT
};
typedef struct {
    Direc direc;
    int line;
    int column;
} info;
typedef struct{
    int x;
    int y;
}coordinate;
#include "draw.h"


void draw(CHAR_INFO consoleBuffer[HIGHT][WIDTH], info tank[]){
    coordinate tank_top[12] = { {0,2}, {0,3}, {1,0}, {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {2,0}, {2,1}, {2,4}, {2,5} };
    coordinate tank_right[12] = { {0,0}, {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {1,4}, {1,5}, {2,0}, {2,1}, {2,2}, {2,3} };
    coordinate tank_down[12] = { {0,0}, {0,1}, {0,4}, {0,5}, {1,0}, {1,1}, {1,2}, {1,3}, {1,4}, {1,5}, {2,2}, {2,3} };
    coordinate tank_left[12] = { {0,2}, {0,3}, {0,4}, {0,5}, {1,0}, {1,1}, {1,2}, {1,3}, {2,2}, {2,3}, {2,4}, {2,5} };
    int i, j;
    int color = (int)BACKGROUND_BLUE;
    for (i = 0; i < 6; i++){
        if (tank[i].direc == TOP){
            for (j = 0; j < 12; j++){
                consoleBuffer[tank[i].line + tank_top[j].x][tank[i].column + tank_top[j].y].Attributes = color;
            }
        }
        else if (tank[i].direc == RIGHT){
            for (j = 0; j < 12; j++){
                consoleBuffer[tank[i].line + tank_right[j].x][tank[i].column + tank_right[j].y].Attributes = color;
            }
        }
        else if (tank[i].direc == DOWN){
            for (j = 0; j < 12; j++){
                consoleBuffer[tank[i].line + tank_down[j].x][tank[i].column + tank_down[j].y].Attributes = color;
            }
        }
        else if (tank[i].direc == LEFT){
            for (j = 0; j < 12; j++){
                consoleBuffer[tank[i].line + tank_left[j].x][tank[i].column + tank_left[j].y].Attributes = color;
            }
        }
    color = (int)BACKGROUND_RED;
    }
}
