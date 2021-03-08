//
// Created by M on 2/28/21.
//

#ifndef COVIDGAME_GAME_H
#define COVIDGAME_GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"


class Game

{
public:
    Game();
    // ~Game();
    void run();
    Player player;

private:
    void processEvents();
    void update(sf::Time);
    void render();
    void handlePlayerInput(sf::Keyboard::Key, bool);
    static float PlayerSpeed;
    static sf::Time TimePerFrame;
    sf::CircleShape mPlayer;

};



#endif //COVIDGAME_GAME_H
