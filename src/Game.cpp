//
// Created by M on 2/28/21.

#include "Game.h"
#include "Player.h"


Game::Game()
{
    this->player = Player();
}



// This function will me measure time each frame takes.
void Game::run()
{
    ;
}

// This functions handles user input
// It will close the game if the user taps Escape button or click close
// We can implement later handlePlayerInput case, to check if the player
// pressed the key or not

void Game::processEvents()
{
    sf::Event event;

    while (mGameWindow.pollEvent(event))
    {
        switch (event.type)
        {
            // case sf::Event::Closed:
            //     // this->app.close();
            //     break;

            // case sf::Event::KeyPressed:
            //     if (event.key.code == sf::Keyboard::Escape)
            //         // this->app.close();
            //     break;

            default:
                break;
        }
    }
}
// it updates the game logic, everything that happens in the game.
void Game::update(elapsedTime)
{
// player movesUP
// player movesDown
// player Shoots
// player rotates
// ETC..
// virus attacks
// virus coughs
    ;
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
