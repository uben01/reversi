#include "Application.hpp"
#include "Menu.hpp"
#include "Widget.hpp"
#include "Button.hpp"
#include "iostream"
#include "stdlib.h"

void Menu::startSinglePlayer()
{
    cout << "SinglePlayer funkcio inditasa";
}
void Menu::startMultiPlayer()
{
    cout << "MultiPlayer funkcio inditasa";
}

Menu :: Menu()
{
    Widget* SinglePlayerButton = new Button(this, 800/2 - 200 / 2,  50, 200, 100, "Egyj�t�kos m�d",     [&](){this->startSinglePlayer();});
    Widget* MultiPlayerButton  = new Button(this, 800/2 - 200 / 2, 250, 200, 100, "T�bbj�t�kos m�d",    [&](){this->startMultiPlayer();});
    Widget* ExitButton         = new Button(this, 800/2 - 200 / 2, 450, 200, 100, "Kil�p�s",            [](){exit(0);});
}

Menu :: ~Menu()
{
    for(Widget* w : elements)
    {
        delete w;
    }
}
