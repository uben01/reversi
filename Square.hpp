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
    Square(Application*, const int&, const int&, const int&, const int&, const bool& = false, const bool& = false);
    const void draw();
    void handle(event&);

    void setOccupied();
    bool isOccupied();
    void setOwner(const bool&);
    bool getOwner();

};

#endif // SQUARE_HPP_INCLUDED
