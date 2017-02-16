typedef enum direction Direc;
enum direction {
    TOP, RIGHT, DOWN, LEFT
};
#include "random.h"

int random_20 (int stop){
    srand(time(NULL));
    return (rand() % 20);
}

int random_76 (int stop){
    srand(time(NULL));
    return (rand() % 76);
}

Direc random_DIREC (){
    srand(time(NULL));
    int r = (rand() % 3);
    switch (r){
        case 0: return TOP;
        case 1: return RIGHT;
        case 2: return DOWN;
        case 3: return LEFT;
    }
}
