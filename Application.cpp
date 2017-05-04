#include "graphics.hpp"
#include "Application.hpp"
#include "Widget.hpp"
#include "Button.hpp"
#include "iostream"

using namespace genv;

void Application::add(Widget* w)
{
    elements.push_back(w);
}

void Application :: event_loop(event & ev)
{
    for (int i = 0; i < elements.size(); i++)
    {
        elements[i]->draw();
    }
    gout << refresh;

    while(gin >> ev)
    {
        if(ev.type == ev_mouse && ev.button == btn_left)
        for(Widget * w : elements)
        {
            if(w->isOver(ev.pos_x, ev.pos_y))
            {
                w->handle(ev);
                break;
            }
        }
    }
}
