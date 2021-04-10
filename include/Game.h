//
// Created by M on 2/28/21.
//

#ifndef COVIDGAME_GAME_H
#define COVIDGAME_GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Stage.h"


class Game

{
public:
    Game(sf::RenderWindow*);

private:
    void update(sf::Int64);
    void handlePlayerInput(sf::Keyboard::Key, bool);
    static sf::Int64 time_per_frame;
    void click(int x, int y); // event.mouseButton is int
    Stage level;
    sf::RenderWindow* app;
};



#endif //COVIDGAME_GAME_H
