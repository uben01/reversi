#include "Application.hpp"
#include "Menu.hpp"
#include "Widget.hpp"
#include "Button.hpp"
#include "iostream"
#include "stdlib.h"

Menu :: Menu()
{
    new Button(this, 1000/2 - 200 / 2,  50, 200, 100, "Egyj�t�kos m�d",     [&](){this->startSinglePlayer();});
    new Button(this, 1000/2 - 200 / 2, 250, 200, 100, "T�bbj�t�kos m�d",    [&](){this->startMultiPlayer();});
    new Button(this, 1000/2 - 200 / 2, 450, 200, 100, "Kil�p�s",            [](){exit(0);});
}

void Menu::startSinglePlayer()
{
    over = true;
    multi_player = false;
}
void Menu::startMultiPlayer()
{
    over = true;
    multi_player = true;
}

bool Menu :: event_loop(event & ev)
{
    drawElements();

    while(gin >> ev && !over)
    {
        if(ev.type == ev_mouse && ev.button == btn_left)
        for(Widget * w : elements)
        {
            if(w->isOver(ev.pos_x, ev.pos_y))
            {
                w->handle(ev);
                break;
            }
        }
    }
    return multi_player;
}
