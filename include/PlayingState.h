//
// Created by M on 4/30/21.
//

#ifndef CSCI437_PLAYINGSTATE_H
#define CSCI437_PLAYINGSTATE_H


#include "State.h"
#include "SpriteActor.h"

class PlayingState: //GameState
        public State
{
private:
    Entity player;
    void initKeyBinds();
    SpriteActor background[192];
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
