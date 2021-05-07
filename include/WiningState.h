//
// Created by M on 5/6/21.
//

#ifndef CSCI437_WININGSTATE_H
#define CSCI437_WININGSTATE_H


#include "Button.h"
#include "PlayingState.h"



class WiningState
        : public State
{
private:
    sf::RectangleShape background;
    sf::Font font;
    sf::Texture backgroundSprite;

    std::map<std::string, Button*>buttons;
    void initKeyBinds();
    void initFonts();
    void initButtons();
    void initBackground();
    void initVariable();

public:
    WiningState(sf::RenderWindow *window, std::map<std::string, int> *supportedKeys,
                 std::stack<State *> *states);
    virtual ~WiningState();

    //functions

    void updateInput(const float& dt);
    void updateButtons();
    void renderButtons(sf::RenderTarget* target = nullptr);
    void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};

#endif //CSCI437_WININGSTATE_H
