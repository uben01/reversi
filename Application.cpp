#include "graphics.hpp"
#include "Application.hpp"
#include "Widget.hpp"
#include "Button.hpp"

using namespace genv;

Application::Application(bool mode)
{
    if(!mode)
    {
        Widget* SinglePlayerButton = new Button(this, 800/2 - 200 / 2, 100, 200, 100, "Egyjátékos mód" );
        Widget* MzultiPlayerButton = new Button(this, 800/2 - 200 / 2, 300, 200, 100, "Többjátékos mód");
    }

}

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

    }
}
