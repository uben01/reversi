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
    Widget(Application * parent, const int& posx, const int& posy, const int& sizex, const int& sizey);

    virtual const void draw() = 0;
    virtual void handle(event& ev) = 0;
};

#endif // WIDGET_HPP_INCLUDED
