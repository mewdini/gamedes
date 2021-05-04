//
// Created by M on 4/30/21.
//

#ifndef CSCI437_PLAYINGSTATE_H
#define CSCI437_PLAYINGSTATE_H


#include "State.h"
#include "SpriteActor.h"
#include "Button.h"
#include "Stage.h"
#include "PlayerView.h"


class PlayingState: //GameState
        public State
{
private:
    void updateButtons();
    void renderButtons(sf::RenderTarget* target);
    sf::Font font;
    std::map<std::string, Button*>buttons;
    Entity player;
    void initButtons();
    void initFonts();
    void initKeyBinds();
    SpriteActor background[192];
    Stage stage;
    PlayerView pView;
public:
    PlayingState(sf::RenderWindow* window,std::map<std::string, int>* supportedKeys, std::stack<State*>*  states);
    virtual ~PlayingState();

    //functions
    void updateInput(const float& dt);
    void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
    
};




#endif //CSCI437_PLAYINGSTATE_H
