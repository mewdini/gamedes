//
// Created by M on 2/28/21.

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "PlayerView.h"
#include "Virus.h"
#include "Tower.h"

int main(int argc, char** argv)
{ 
    sf::Clock delta;
    sf::Time dt;

    // TODO handle time

    PlayerView::PlayerView p_view;
    Game::Game game(&p_view);

    // Done.
    return 0;
}








