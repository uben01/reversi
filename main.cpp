#include "graphics.hpp"
#include "Application.hpp"
#include "Widget.hpp"

using namespace std;
using namespace genv;

int main()
{
    gout.open(800,600);
    event ev;

    Application app(false);
    app.event_loop(ev);

    return 0;
}
