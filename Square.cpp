#include "Square.hpp"
#include "Application.hpp"
#include "Game.hpp"
#include "rgb.hpp"
#include "graphics.hpp"
#include "iostream"
#include <math.h>

Square :: Square(Application* parent, const int& posx, const int& posy, const int& sizex, const int& sizey)
    : Widget(parent, posx, posy, sizex, sizey)
{
    occupied = false;
    owner = false;

}

const void Square :: draw()
{
    gout << move_to(_posx, _posy)
         << color(0,0,0)
         << box(squareSize, squareSize)

         << move_to(_posx + 1, _posy + 1)
         << color(120,255,120)
         << box(squareSize - 2, squareSize - 2);

    if(occupied)
    {
        rgb* c;
        if(owner)
        {
            c = new rgb(255,255,255);
        }
        else
        {
            c = new rgb(0,0,0);
        }
        c->setcolor();
        for(int i = 0; i <  squareSize; i++)
        {
            for (int j = 0; j <  squareSize; j++)
            {
                if( pow(i - (_sizex) / 2, 2) + pow(j - (_sizey) / 2, 2) <= squareSize*10 )
                {
                    //cout << "asd";
                    gout << move_to(i+ _posx,j+ _posy)
                         << dot;
                }
            }
        }
    }
}

void Square :: handle(event& ev)
{
    if(!occupied)
    {
        cout << endl;
        cout << "X: " << int(_posx/squareSize) + 1 << endl;
        cout << "Y: " << int(_posy/squareSize) + 1 << endl;

        Game* parent = dynamic_cast<Game*>(_parent);
        if(parent)
        {
            occupied = true;
            owner = parent->getPlayer();
            parent->changePlayer();
        }
    }
}
