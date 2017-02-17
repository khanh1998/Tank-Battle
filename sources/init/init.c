#include "init.h"

void init (CHAR_INFO consoleBuffer[HIGHT][WIDTH], info tank[], int numOfTank){
    int i, j, check = 0;
    //player's tank
    tank[0].column = 36;
    tank[0].line = 36 ;
    tank[0].direc = TOP;
    //another tank
    srand(time(NULL));
    for (i = 1; i <= numOfTank; i++){
        check = 0;
        while (!check){
            tank[i].column = random_73();
            tank[i].line = random_20();
            tank[i].direc = random_DIREC();
            check = 1;
            for (j = 0; j < i; j++){
                if ((tank[i].column > (tank[j].column - 5)) && ((tank[i].column) < (tank[j].column + 6))
                   && (tank[i].line > (tank[j].line - 2)) && (tank[i].line > (tank[j].line + 6))
                    ){
                    check = 0;
                }
            }
        }

    }
    draw(consoleBuffer, tank);
}
