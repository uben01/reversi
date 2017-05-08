#include "Application.hpp"
#include "Widget.hpp"
#include "Game.hpp"
#include "Square.hpp"
#include "TextBox.hpp"
#include "iostream"
#include "stdlib.h"
#include <sstream>

int XX;
int YY;


Game :: Game(const int& xx, const int& yy)
{
    activePlayer = false;
    XX = xx;
    YY = yy;
    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 8; i++)
        {
            bool oc = false, ow = false;
            if((i == 3 || i == 4) && (j == 3 || j == 4))
            {
                oc = true;
                if((i == 4 && j == 3) || (i == 3 && j == 4)) ow = true;
            }
            Widget* e = new Square(this, i * squareSize, j * squareSize, squareSize, squareSize, oc, ow);
        }
    }


    ////////////////////////////////////////////
    Widget* white_player_score = new TextBox(this, 800, 100, 200, 100, "", new rgb(0,0,0));
    Widget* dark_player_score = new TextBox(this, 800, 200, 200, 100, "", new rgb(255,255,255));

    Widget* message = new TextBox(this, 800, 600, 200, 100, "A jatek elkezdodott\nFeher kezd", new rgb(255,255,255));

}

void Game :: event_loop(event& ev)
{
    gout << move_to(0,0)
         << color(125,125,125)
         << box(XX, YY);

    countPoints();
    drawElements();

    while(gin >> ev)
    {
        if(ev.type == ev_mouse && ev.button == btn_left)
        {
            pp_clear();
            for(Widget * w : elements)
            {
                if(w->isOver(ev.pos_x, ev.pos_y))
                {
                    w->handle(ev);
                    drawElements();
                    if(!canAct())
                    {
                        string s = ((!activePlayer) ? "Feher" : "Fekete");
                        string ns = ((activePlayer) ? "Feher" : "Fekete");
                        string msg = s + " nem tud lepni\n" + ns + " kovetkezik";
                        setMessage(msg);

                        changePlayer();

                        if(!canAct())
                        {
                            string s = ((countPoints()) ? "feher" : "fekete");
                            string msg = "A jateknak vege, \n" + s + " nyert";
                            setMessage(msg);
                        }
                    } else
                    {
                        string s = ((!activePlayer) ? "Feher" : "Fekete");
                        string msg = s + " kovetkezik";
                        setMessage(msg);
                    }
                    countPoints();
                    break;
                }
            }
        }
        else if(ev.type == ev_mouse)
        {
            pp_clear();
            int x = ev.pos_x/squareSize, y = ev.pos_y/squareSize;
            if(x < 8 && x >= 0 && y < 8 && y >= 0) testElement(x, y);
            drawElements();
        }
    }
}
void Game::changePlayer()
{
    activePlayer = !activePlayer;
}
bool Game::getPlayer()
{
    return activePlayer;
}


bool Game :: isOrderly(int p_x, int p_y, int x_dir, int y_dir, int depth, bool test)
{
    p_x += x_dir;
    p_y += y_dir;
    if(p_x < 0 || p_y < 0 || p_x > 7 || p_y > 7) return false;
    Square* element = dynamic_cast<Square*> (elements[p_y * 8 + p_x]);
    if(element)
    {
        if(depth == 1 && element->getOwner() == getPlayer()) return false;
        if(!element->isOccupied()) return false;

        if(element->getOwner() == getPlayer()) return true;
        else
        {
            bool last = isOrderly(p_x, p_y, x_dir, y_dir, depth + 1, test);
            if(last)
            {
                if(!test) element->setOwner(getPlayer());
                else pp_add(p_y * 8 + p_x);
                return true;
            }
        }
    }
    return false;
}

bool Game :: canAct()
{
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            if(testElement(x, y)) return true;
        }
    }
    return false;
}

bool Game :: testElement(int x, int y)
{
    bool isGood = false;
    Square* element = dynamic_cast<Square*>(elements[y * 8 + x]);
    if(element && !element->isOccupied())
    {
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                if(i != 0 || j != 0)
                {
                    if(isOrderly(x, y, i, j, 1, true)) isGood = true;
                }
            }
        }
    }
    return isGood;
}

void Game :: pp_add(int a)
{
    possible_positions.push_back(a);
}

void Game :: pp_clear()
{
    possible_positions.clear();
}

vector<int> Game :: get_pp()
{
    return possible_positions;
}


bool Game :: countPoints()
{
    int dark  = 0;
    int white = 0;
    for(int i = 0; i < 8*8; i++)
    {
        Square* element = dynamic_cast<Square*>(elements[i]);
        if(element && element->isOccupied())
        {
            if(element->getOwner()) white++;
            else dark++;
        }
    }
    TextBox* white_player_score = dynamic_cast<TextBox*>(elements[8*8]);
    TextBox* dark_player_score = dynamic_cast<TextBox*>(elements[8*8 + 1]);

    stringstream ss;
    string score;
    ss << white;
    ss >> score;
    white_player_score->setText( "Pont: " +  score );
    ss.clear();

    ss << dark;
    ss >> score;
    dark_player_score->setText( "Pont: " +  score );

    return dark > white;
}

void Game :: setMessage(string s)
{
    TextBox* msgbox = dynamic_cast<TextBox*>(elements[8*8 + 2]);
    msgbox->setText( s );

}
