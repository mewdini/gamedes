//
// Created by M on 2/28/21.
//

#ifndef COVIDGAME_GAME_H
#define COVIDGAME_GAME_H

#include <SFML/Graphics.hpp>
#include "Stage.h"
#include "Player.h"
#include "PlayerView.h"



class Game

{
public:
    Game(PlayerView*);

private:
    void update(sf::Int64);
    sf::Int64 time_per_frame;
    void click(int x, int y); // event.mouseButton is int
    Stage level;
    sf::RenderWindow* app;
    PlayerView* view;
};



#endif //COVIDGAME_GAME_H
