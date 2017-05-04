#ifndef MENU_HPP_INCLUDED
#define MENU_HPP_INCLUDED

#include "Application.hpp"

class Menu : public Application
{
public:
    Menu();
    ~Menu();

    void startSinglePlayer();
    void startMultiPlayer();
};

#endif // MENU_HPP_INCLUDED
