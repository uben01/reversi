#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <vector>
#include "graphics.hpp"

using namespace std;
using namespace genv;

class Widget;

class Application
{
protected:
    vector<Widget*> elements;

public:
    ~Application();

    void add(Widget*);
    void drawElements();

    virtual void event_loop(event&) = 0;

};

#endif // APPLICATION_HPP_INCLUDED
