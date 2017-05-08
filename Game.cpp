#include "Application.hpp"
#include "Widget.hpp"
#include "Game.hpp"
#include "Square.hpp"
#include "iostream"
#include "stdlib.h"

int XX;
int YY;


Game :: Game(const int& xx, const int& yy)
{
    activePlayer = false;
    XX = xx;
    YY = yy;
    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 8; i++)
        {
            bool oc = false, ow = false;
            if((i == 3 || i == 4) && (j == 3 || j == 4))
            {
                oc = true;
                if((i == 4 && j == 3) || (i == 3 && j == 4)) ow = true;
            }
            Widget* e = new Square(this, i * squareSize, j * squareSize, squareSize, squareSize, oc, ow);
        }
    }



}

void Game :: event_loop(event& ev)
{
    gout << move_to(0,0)
         << color(0,0,0)
         << box(XX, YY);

    drawElements();

    while(gin >> ev)
    {
        if(ev.type == ev_mouse && ev.button == btn_left)
        {
            pp_clear();
            for(Widget * w : elements)
            {
                if(w->isOver(ev.pos_x, ev.pos_y))
                {
                    w->handle(ev);
                    drawElements();
                    if(!canAct())
                    {
                        /// egyik nem léphet
                        changePlayer();

                        if(!canAct())
                        {
                            exit(0);
                            ///vége
                        }
                    }
                    /// Jobb oldalra eredményjelzõ
                }
            }
        }
        else if(ev.type == ev_mouse)
        {
            pp_clear();
            int x = ev.pos_x/squareSize, y = ev.pos_y/squareSize;
            testElement(x, y);
            drawElements();
        }
    }
}
void Game::changePlayer()
{
    activePlayer = !activePlayer;
}
bool Game::getPlayer()
{
    return activePlayer;
}


bool Game :: isOrderly(int p_x, int p_y, int x_dir, int y_dir, int depth, bool test)
{
    p_x += x_dir;
    p_y += y_dir;
    if(p_x < 0 || p_y < 0 || p_x > 7 || p_y > 7) return false;
    Square* element = dynamic_cast<Square*> (elements[p_y * 8 + p_x]);
    if(element)
    {
        if(depth == 1 && element->getOwner() == getPlayer()) return false;
        if(!element->isOccupied()) return false;

        if(element->getOwner() == getPlayer()) return true;
        else
        {
            bool last = isOrderly(p_x, p_y, x_dir, y_dir, depth + 1, test);
            if(last)
            {
                if(!test) element->setOwner(getPlayer());
                else pp_add(p_y * 8 + p_x);
                return true;
            }
        }
    }
    return false;
}

bool Game :: canAct()
{
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            if(testElement(x, y)) return true;
        }
    }
    return false;
}

bool Game :: testElement(int x, int y)
{
    Square* element = dynamic_cast<Square*>(elements[y * 8 + x]);
    if(element && !element->isOccupied())
    {
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                if(i != 0 || j != 0)
                {
                    if(isOrderly(x, y, i, j, 1, true)) return true;
                }
            }
        }
    }
    return false;
}

void Game :: pp_add(int a)
{
    possible_positions.push_back(a);
}

void Game :: pp_clear()
{
    possible_positions.clear();
}

vector<int> Game :: get_pp()
{
    return possible_positions;
}
