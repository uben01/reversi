#include "Application.hpp"
#include "Menu.hpp"
#include "Widget.hpp"
#include "Button.hpp"
#include "iostream"
#include "stdlib.h"

Menu :: Menu()
{
    Widget* SinglePlayerButton = new Button(this, 800/2 - 200 / 2,  50, 200, 100, "Egyj�t�kos m�d",     [&](){this->startSinglePlayer();});
    Widget* MultiPlayerButton  = new Button(this, 800/2 - 200 / 2, 250, 200, 100, "T�bbj�t�kos m�d",    [&](){this->startMultiPlayer();});
    Widget* ExitButton         = new Button(this, 800/2 - 200 / 2, 450, 200, 100, "Kil�p�s",            [](){exit(0);});
}

void Menu::startSinglePlayer()
{
    cout << "SinglePlayer funkcio inditasa";
    over = true;
}
void Menu::startMultiPlayer()
{
    cout << "MultiPlayer funkcio inditasa";
}

void Menu :: event_loop(event & ev)
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
}
