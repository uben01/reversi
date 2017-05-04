#ifndef RGB_HPP_INCLUDED
#define RGB_HPP_INCLUDED

#include "graphics.hpp"


struct rgb
{
    int r;
    int g;
    int b;
    rgb(int rr, int gg, int bb) : r(rr), g(gg), b(bb){};

    void setcolor()
    {
        genv::gout << genv::color(r,g,b);
    }
};

#endif // RGB_HPP_INCLUDED
