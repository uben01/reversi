#include "graphics.hpp"
#include "Application.hpp"
#include "Widget.hpp"
#include "Menu.hpp"
#include "Game.hpp"

using namespace std;
using namespace genv;

const int XX = 800;
const int YY = 800;

int main()
{
    gout.open(XX,YY);
    event ev;

    Menu* menu = new Menu();
    menu->event_loop(ev);
    delete menu;
    Game* game = new Game(XX, YY);
    game->event_loop(ev);


    return 0;
}
