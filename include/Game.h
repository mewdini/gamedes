//
// Created by M on 2/28/21.
//

#ifndef COVIDGAME_GAME_H
#define COVIDGAME_GAME_H

#include "MainMenuState.h"
#include "Player.h"
#include "Stage.h"
#include "PlayerView.h"
#include "EndGameState.h"



class Game

{
public:
    //Game(PlayerView*);
    Game();
    virtual ~Game();

    //reg
    void endApplication();
    //update
    void updateSFMLEvents();
    void update();
    void updateDt();

    //render
    void render();
    //core
    void run();
private:
    //Variables
    //delta time
    sf::Clock dtClock;
    float dt;
    std::stack<State*> states;
    std::map<string, int> supportedKeys;
    //initialization
    void initKeys();
    sf::RenderWindow *window;
    sf::Event sfEvent;

    //Initialization
    void initWindow();
    void initStates();


//    void update(sf::Int64);
//    sf::Int64 time_per_frame;
//    void click(int x, int y); // event.mouseButton is int
//    Stage level;
//    sf::RenderWindow* app;
//    PlayerView* view;
};



#endif //COVIDGAME_GAME_H
