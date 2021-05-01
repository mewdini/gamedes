//
// Created by M on 4/29/21.
//

#ifndef CSCI437_MAINMENUSTATE_H
#define CSCI437_MAINMENUSTATE_H

#include "PlayingState.h"
#include "Button.h"


class MainMenuState
        : public State
{
private:
    sf::RectangleShape background;
    sf::Font font;

    std::map<std::string, Button*>buttons;
    //Button* mainMenuButton;
    //func
    void initKeyBinds();
    void initFonts();
    void initButtons();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,std::stack<State*>*  states);
    virtual ~MainMenuState();

    //functions
    //int statenumber();
    void updateInput(const float& dt);
    void updateButtons();
    void renderButtons(sf::RenderTarget* target = nullptr);
    void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};


#endif //CSCI437_MAINMENUSTATE_H
