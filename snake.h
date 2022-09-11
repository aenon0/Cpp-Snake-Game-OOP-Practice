#include "snake.h"
#define HEIGHT 25
#define WIDTH 50


COORD pos;
snake::snake(COORD pos, int speed)
{
     this->pos = pos;
     this->speed = speed;
     length=1;
     direction= 'n';

     body.push_back(pos);

}

void snake::change_dir(char dir)/// the snake's direction
      {direction = dir;}
void snake::grow()
     {length++;}
COORD snake::get_pos() {return pos;}

vector<COORD> snake::get_body(){return body;}

void snake::move_snake()
      {
          switch(direction)
          {
              case 'u' : pos.Y -=speed;break;
              case 'd' : pos.Y +=speed;break;
              case 'l' : pos.X -=speed;break;
              case 'r' : pos.X +=speed;break;
          }
          body.push_back(pos);
     if(body.size()>length) body.erase(body.begin());
      }





bool snake::eaten(COORD food_pos)
{
    if(food_pos.X==pos.X && food_pos.Y==pos.Y) return true;
    else return false;

}



bool snake::collided()
{
    if (pos.X<1 || pos.X>WIDTH-2 || pos.Y<=1 || pos.Y>HEIGHT-1) return true;
    else return false;

}
