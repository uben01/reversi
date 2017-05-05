#include "Square.hpp"
#include "Application.hpp"
#include "Game.hpp"
#include "rgb.hpp"
#include "graphics.hpp"
#include "iostream"
#include <math.h>

Square :: Square(Application* parent, const int& posx, const int& posy, const int& sizex, const int& sizey, const bool& oc, const bool& ow)
    : Widget(parent, posx, posy, sizex, sizey)
{
    occupied = oc;
    owner = ow;

}

const void Square :: draw()
{
    gout << move_to(_posx, _posy)
         << color(0,0,0)
         << box(squareSize, squareSize)

         << move_to(_posx + 1, _posy + 1)
         << color(60,255,60)
         << box(squareSize - 2, squareSize - 2);

    if(occupied)
    {
        rgb* c;
        if(owner)
        {
            c = new rgb(0,0,0);
        }
        else
        {
            c = new rgb(255,255,255);
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
        int x = _posx/squareSize, y = _posy/squareSize;

        //cout << endl;
        //cout << "X: " << x + 1 << endl;
        //cout << "Y: " << y + 1 << endl;


        Game* parent = dynamic_cast<Game*>(_parent);
        if(parent)
        {
            bool isGood = false;
            for(int i = -1; i <= 1; i++)
            {
                for(int j = -1; j <= 1; j++)
                {
                    if(i != 0 || j != 0)
                    {
                        if(parent->isOrderly(x, y, i, j, 1)) isGood = true;
                    }
                }
            }
            if(isGood)
            {
                occupied = true;
                owner = parent->getPlayer();
                parent->changePlayer();
            }
        }
    }
}

void Square :: setOccupied()
{
    occupied = true;
}

bool Square :: isOccupied()
{
    return occupied;
}
bool Square :: getOwner()
{
    return owner;
}
void Square :: setOwner(const bool& b)
{
    owner = b;
}
