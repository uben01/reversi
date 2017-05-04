#include "Application.hpp"
#include "Widget.hpp"
#include "Game.hpp"
#include "Square.hpp"

int XX;
int YY;

Game :: Game(const int& xx, const int& yy)
{
    activePlayer = false;
    XX = xx;
    YY = yy;
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            Widget* e = new Square(this, i*squareSize, j*squareSize, squareSize, squareSize);
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
