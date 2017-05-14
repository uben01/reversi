#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Application.hpp"

class Square;

class Game : public Application
{
    bool multiPlayer;
    bool activePlayer;
    vector<int> possible_positions;
public:
    Game(const int&, const int&, const bool&);

    virtual bool event_loop(event&);
    bool getPlayer();
    void changePlayer();

    bool isOrderly(int, int, int, int, int, bool);
    bool canAct();
    bool testElement(int, int);

    bool countPoints();
    void setMessage(string);

    void pp_add(int);
    void pp_clear();
    vector<int> get_pp();

    int getComputerMove(vector<Square>, int, bool, int);
};

#endif // GAME_HPP_INCLUDED
