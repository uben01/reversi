#ifndef SQUARE_HPP_INCLUDED
#define SQUARE_HPP_INCLUDED

#include "Widget.hpp"
#include "Application.hpp"

const int squareSize = 100;

class Square : public Widget
{
    bool occupied;
    bool owner; // false - fehér, true - fekete ---- Nincs jelentõsége amig az owner false

public:
    Square(Application*, const int&, const int&, const int&, const int&);
    const void draw();
    void handle(event&);
};

#endif // SQUARE_HPP_INCLUDED
