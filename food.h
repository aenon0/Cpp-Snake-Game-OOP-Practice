#include "food.h"
#define HEIGHT 25
#define WIDTH 50


void food::generate_food()
{
    pos.X=(rand()%(WIDTH-4))+1;
    pos.Y=(rand()%(HEIGHT-4))+1;
}

COORD food::get_pos(){return pos;}
