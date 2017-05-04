#include "graphics.hpp"
#include "Application.hpp"
#include "Widget.hpp"
#include "Button.hpp"
#include "iostream"

using namespace genv;

Application::~Application()
{
    for(Widget* w : elements)
    {
        delete w;
    }
}

void Application::add(Widget* w)
{
    elements.push_back(w);
}

void Application::drawElements()
{
    for (int i = 0; i < elements.size(); i++)
    {
        elements[i]->draw();
    }
    gout << refresh;
}

