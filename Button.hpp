#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include "graphics.hpp"
#include "Widget.hpp"

using namespace std;
using namespace genv;

class Button : public Widget
{
    const string _title;

public:
    Button(Application * parent, const int& posx, const int& posy, const int& sizex, const int& sizey, const string& title): Widget(parent, posx, posy, sizex, sizey), _title(title){}

    const void draw();
    void handle(event& ev);
};

#endif // BUTTON_HPP_INCLUDED
