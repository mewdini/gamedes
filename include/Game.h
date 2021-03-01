//
// Created by M on 2/28/21.
//

#ifndef COVIDGAME_GAME_H
#define COVIDGAME_GAME_H

#include <SFML/Graphics.hpp>


class Game

{
public:
    Game();
    ~Game();
    void run();
private:
    void processEvents();
    void update(sf::Time elapsedTime);
    void render();
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    static const float PlayerSpeed;
    static const float sf::Time TimePerFrame;
    sf::RenderWindow mGameWindow;
    sf::CircleShape mPlayer;

};



#endif //COVIDGAME_GAME_H
