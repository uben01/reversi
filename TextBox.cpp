#include "Widget.hpp"
#include "Application.hpp"
#include "rgb.hpp"
#include "TextBox.hpp"

TextBox :: TextBox(Application* parent, const int& posx, const int& posy, const int& sizex, const int& sizey, const string& s, rgb* c)
    : Widget(parent, posx, posy, sizex, sizey)
{
    _value = s;
    _color = c;
}

const void TextBox :: draw()
{
    gout << move_to(_posx, _posy)
         << color(120,120,120)
         << box(_sizex, _sizey);
    _color->setcolor();
    gout << move_to(_posx + 10, ((_posy*2+_sizey) / 2))
         << text(_value);
}
void TextBox :: handle(event& ev){}



string TextBox::getText()
{
    return _value;
}
void TextBox::setText(string s)
{
    _value = s;
}
