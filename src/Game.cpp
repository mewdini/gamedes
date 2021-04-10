// Created by M on 2/28/21.

#include "Game.h"
#include "Player.h"


Game::Game(sf::RenderWindow* window)
{
    this->app = window;
}

// it updates the game logic, everything that happens in the game.
void Game::update(sf::Int64 elapsed_time)
{
    this->time_per_frame = elapsed_time;
    // all towers attack
    // germs move
}

// TODO never hardcode keys, use config files
// also, user input should be handled in player view and sent as event to eventmanager
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
        //player is moving UP;

    else if (key == sf::Keyboard::S)
        //player is moving DOWN;

    else if (key == sf::Keyboard::A)
        //player is moving Left;

    else if (key == sf::Keyboard::D)
        //player is moving Right;
}

void Game::click(int x, int y)
{
    while (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // draw tower at cursor location 
        ;
    }

    // try to build tower here (tower build function should return false if not enough money or invalid position)
    bool worked;
    auto mouse_pos = sf::Mouse::getPosition(app);
    worked = level.build(towerType, mouse_pos.x, mouse_pos.y);
    
    if (!worked)
    {
        // show that failed
        ;
    }
}