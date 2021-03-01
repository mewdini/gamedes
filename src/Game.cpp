//
// Created by M on 2/28/21.

#include "Game.h"


Game::Game()
: mGameWindow(sf::VideoMode(600, 800), "Covid Champion", sf::Style::Titlebar | sf::Style::Close);
, mPlayer()



// This function will me measure time each frame takes.
void Game::run()
{

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
            case Event::Closed:
                App.close();
                break;

            case Event::KeyPressed:
                if (event.key.code == Keyboard::Escape)
                    App.close();
                break;

            default:
                break;
        }
    }
}
// it updates the game logic, everything that happens in the game.
void Game::update()
{
// player movesUP
// player movesDown
// player Shoots
// player rotates
// ETC..
// virus attacks
// virus coughs



}



void Game::render()
{
    mGameWindow.clear();
    mGameWindow.draw(mPlayer);
    mWindow.display();
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
    if (key == sf::Keyboard::W)
        //player is moving UP;

    else if (key == sf::Keyboard::S)
        //player is moving DOWN;

    else if (key == sf::Keyboard::A)
        //player is movig Left;

    else if (key == sf::Keyboard::D)
        //player is moving Right;


}






//

