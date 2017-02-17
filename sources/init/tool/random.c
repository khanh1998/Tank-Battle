typedef enum direction Direc;
enum direction {
    TOP, RIGHT, DOWN, LEFT
};
#include "random.h"

int random_20 (int stop){
    
    return (rand() % 20);
}

int random_73 (int stop){
    
    return (rand() % 73);
}

Direc random_DIREC (){
    
    int r = (rand() % 3);
    switch (r){
        case 0: return TOP;
        case 1: return RIGHT;
        case 2: return DOWN;
        case 3: return LEFT;
    }
}
