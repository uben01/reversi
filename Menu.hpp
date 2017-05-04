#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "Application.hpp"

class Menu : public Application
{
    bool over = false;
public:
    Menu();

    void event_loop(event&);

    void startSinglePlayer();
    void startMultiPlayer();
};

#endif // MENU_HPP_INCLUDED
