#include "Widget.hpp"
#include "Application.hpp"
#include "Button.hpp"

using namespace genv;
using namespace std;

const void Button :: draw()
{
    gout << move_to(_posx, _posy)
         << color(255,255,255)
         << box(_sizex, _sizey);

    gout << move_to(_posx + 2, _posy + 2)
         << color(0,0,0)
         << box(_sizex - 4, _sizey - 4);

    gout << move_to((_posx + _posx + _sizex) / 2 - gout.twidth(_title)/2, (_posy + _posy + _sizey) / 2 + gout.cascent() / 2)
         << color(255,255,255)
         << text(_title);
}

void Button :: handle(event& ev)
{
    _functor();
}
