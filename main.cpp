#include "graphics.hpp"
#include "Application.hpp"
#include "Widget.hpp"
#include "Menu.hpp"

using namespace std;
using namespace genv;


int main()
{
    gout.open(800,600);
    event ev;

    Menu* menu = new Menu();
    menu->event_loop(ev);
    delete menu;

    return 0;
}
