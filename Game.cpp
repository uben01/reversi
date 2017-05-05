#include "Application.hpp"
#include "Widget.hpp"
#include "Game.hpp"
#include "Square.hpp"
#include "iostream"

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
            for(Widget * w : elements)
            {
                if(w->isOver(ev.pos_x, ev.pos_y))
                {
                    w->handle(ev);
                    drawElements();
                }
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


bool Game :: isOrderly(int p_x, int p_y, int x_dir, int y_dir, int depth)
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
            bool last = isOrderly(p_x, p_y, x_dir, y_dir, depth + 1);
            if(last)
            {
                element->setOwner(getPlayer());
                return true;
            }
        }
    }
    return false;
}
