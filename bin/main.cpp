//
// Created by M on 2/28/21.

//#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
    sf::RenderWindow mGameWindow(sf::VideoMode(800, 600, 32), "Covid Champion", sf::Style::Close);
    Game game;
    game.run();
}








