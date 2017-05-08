#ifndef TEXTBOX_HPP_INCLUDED
#define TEXTBOX_HPP_INCLUDED

#include "Widget.hpp"
#include "Application.hpp"
#include "rgb.hpp"

class TextBox : public Widget
{
    string _value;
    rgb* _color;

public:
    TextBox(Application*, const int&, const int&, const int&, const int&, const string&, rgb*);
    const void draw();
    void handle(event&);

    string getText();
    void setText(string);
};

#endif // TEXTBOX_HPP_INCLUDED
