typedef enum direction Direc;
enum direction {
    TOP, RIGHT, DOWN, LEFT
};
typedef struct {
    Direc direc;
    int line;
    int column;
} info;
#include "tool/draw.h"
#include "tool/random.h"



void init (CHAR_INFO consoleBuffer[HIGHT][WIDTH], info tank[]);
