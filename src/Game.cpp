// Created by M on 2/28/21.

#include "Game.h"
#include "Player.h"


Game::Game(PlayerView* p_view)
{
    view = p_view;
}

// it updates the game logic, everything that happens in the game.
void Game::update(sf::Int64 elapsed_time)
{
    level.update(elapsed_time);
}

void Game::click(int x, int y)
{
    while (view->isButtonPressed(sf::Mouse::Left))
    {
        // tell player view to draw tower at cursor location
        ;
    }

    // try to build tower here (tower build function should return false if not enough money or invalid position)
    bool worked;
    auto mouse_pos = view->getMousePos();
    worked = level.build(1, mouse_pos.x, mouse_pos.y);
    
    if (!worked)
    {
        // tell player view to show that failed
        ;
    }
}