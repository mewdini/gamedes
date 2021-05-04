//
// Created by M on 4/29/21.
//

#pragma once


#include "Button.h"
#include "MainMenuState.h"


class EndGameState
        : public State
{
private:
    sf::RectangleShape background;
    sf::Font font;
    sf::Texture backgroundSprite;

    std::map<std::string, Button*>buttons;
    //Button* mainMenuButton;
    //func
    void initKeyBinds();
    void initFonts();
    void initButtons();
    void initBackground();
    void initVariable();

public:
    EndGameState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,std::stack<State*>*  states);
    virtual ~EndGameState();

    //functions

    void updateInput(const float& dt);
    void updateButtons();
    void renderButtons(sf::RenderTarget* target = nullptr);
    void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};


