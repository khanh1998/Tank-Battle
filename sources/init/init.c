#include "init.h"

void init (CHAR_INFO consoleBuffer[HIGHT][WIDTH], info tank[]){
    int i, numOfTank = 5;
    //player's tank
    tank[0].column = 36;
    tank[0].line = 33;
    tank[0].direc = TOP;
    //another tank
    for (i = 1; i <= numOfTank; i++){
        tank[i].column = random_76();
        tank[i].line = random_20();
        tank[i].direc = random_DIREC();
    }
    draw(consoleBuffer, tank);
}
