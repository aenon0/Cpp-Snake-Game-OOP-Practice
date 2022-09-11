///SNAKE GAME
#include <iostream>
 ///a library that controls the console, it has commands like cls and etc.
#include <windows.h> ///a library that gives us control over the cursor but we can cancel it since it's used in the classes
#include <conio.h> ///helps us to get direction from the user
#include <ctime>

#include "snake.h"
#include "food.h"

using namespace std;


#define HEIGHT 25
#define WIDTH 50
 int x=10, y=10;
 snake snake ({WIDTH/2, HEIGHT/2}, 1);
 food food;


///doing the board of the game
void board()
    {
      COORD snake_pos =  snake.get_pos();
      COORD food_pos = food.get_pos();

      vector<COORD> snake_body = snake.get_body();

      for (int i=1; i<=HEIGHT; i++)
          {
               cout<<'\t'<<'\t'<<'\t';///putting the board in the middle
               if (i==1 || i==HEIGHT) ///doing the upper and the lower border
                      {
                          for (int j=1; j<=WIDTH; j++) {cout<<"#";}
                          cout<<endl;
                      }
               else///doing the side boards and the the inner space
                      {
                          cout<<"#";
                          for (int j=1;j<=WIDTH-2;j++)
                                 {if (i==snake_pos.Y && j==snake_pos.X) {cout<<"@";}///setting the snake's head
                                  else if (i==food_pos.Y && j==food_pos.X){cout<<'*';}
                                  else
                                    {
                                       bool is_body_part= false;
                                       for(int k=0;k<snake_body.size()-1;k++)
                                       {
                                           if (i==snake_body[k].Y && j==snake_body[k].X)
                                            {
                                                cout<<"O";
                                                is_body_part=true;
                                                break;
                                            }
                                       }
                                       if (!is_body_part) cout<<" ";

                                    }
                                 }
                          cout<<"#"<<endl;
                      }
           }

    }



int main()
{
    srand(time(NULL));
    food.generate_food();

    bool game_over= false;

    while (!game_over)
    {
        cout<<"\n"<<endl;
        board();
        if (kbhit())
        {
            switch(getch())
            {
                case 'a': snake.change_dir('l');break;
                case 'w': snake.change_dir('u');break;
                case 'd': snake.change_dir('r');break;
                case 's': snake.change_dir('d');break;
            }
        }

        if (snake.eaten (food.get_pos()))
        {
            food.generate_food();
            snake.grow();
        }

        if(snake.collided()) game_over=true;
        snake.move_snake();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0,0} );
    }
}
