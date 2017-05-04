#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <vector>

using namespace std;
using namespace genv;

class Widget;

class Application
{
    vector<Widget*> elements;

public:
    Application(bool mode);
    void add(Widget* w);

    void event_loop(event& ev);

};

#endif // APPLICATION_HPP_INCLUDED
