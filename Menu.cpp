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
    Widget* SinglePlayerButton = new Button(this, 800/2 - 200 / 2,  50, 200, 100, "Egyjátékos mód",     [&](){this->startSinglePlayer();});
    Widget* MultiPlayerButton  = new Button(this, 800/2 - 200 / 2, 250, 200, 100, "Többjátékos mód",    [&](){this->startMultiPlayer();});
    Widget* ExitButton         = new Button(this, 800/2 - 200 / 2, 450, 200, 100, "Kilépés",            [](){exit(0);});
}

Menu :: ~Menu()
{
    for(Widget* w : elements)
    {
        delete w;
    }
}
