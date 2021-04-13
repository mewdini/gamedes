//
// Created by M on 2/28/21.
//

#ifndef COVIDGAME_GAME_H
#define COVIDGAME_GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Stage.h"
#include "PlayerView.h"



class Game

{
public:
    Game(sf::RenderWindow*, PlayerView*);
    ~Game();

private:
    void update(sf::Int64);
    static sf::Int64 time_per_frame;
    void click(int x, int y); // event.mouseButton is int
    Stage level;
    sf::RenderWindow* app;
    PlayerView* view;
    enum Towers {first};
};



#endif //COVIDGAME_GAME_H
