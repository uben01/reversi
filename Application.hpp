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
    void add(Widget*);

    void event_loop(event&);

};

#endif // APPLICATION_HPP_INCLUDED
