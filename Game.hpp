#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Application.hpp"

class Game : public Application
{
    bool activePlayer;
public:
    Game(const int&, const int&);

    void event_loop(event&);
    bool getPlayer();
    void changePlayer();

    bool isOrderly(int, int, int, int, int);
};

#endif // GAME_HPP_INCLUDED
