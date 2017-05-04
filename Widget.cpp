#include "Widget.hpp"
#include "Application.hpp"


Widget :: Widget(Application * parent, const int& posx, const int& posy, const int& sizex, const int& sizey)
    : _parent(parent), _posx(posx), _posy(posy), _sizex(sizex), _sizey(sizey)
{
    _parent->add(this);
}
