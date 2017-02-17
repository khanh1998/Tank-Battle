#include <windows.h>
typedef enum direction Direc;
enum direction {
    TOP, RIGHT, DOWN, LEFT
};
#include "input.h"

Direc readkey(){
	if (GetAsyncKeyState(VK_UP)){
        return TOP;
    }
    else if (GetAsyncKeyState(VK_RIGHT)){
    	return RIGHT;
    }
    else if (GetAsyncKeyState(VK_DOWN)){
    	return DOWN;
    }
    else if (GetAsyncKeyState(VK_LEFT)){
    	return LEFT;
    }
}


