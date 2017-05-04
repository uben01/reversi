#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"

using namespace std;
using namespace genv;

class Application;

class Widget
{
protected:
    const int _posx;
    const int _posy;
    const int _sizex;
    const int _sizey;

    Application* _parent;

public:
    Widget(Application*, const int&, const int&, const int&, const int&);

    const bool isOver(int, int);
    virtual const void draw() = 0;
    virtual void handle(event& ev) = 0;
};

#endif // WIDGET_HPP_INCLUDED
