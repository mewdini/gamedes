//
// Created by M on 4/28/21.
//

#ifndef CSCI437_STATE_H
#define CSCI437_STATE_H

//#include <vector>
#include "Entity.h"

class State
{
private:

protected:
    //not a copy but a pointer to a stack full of state pointers in game.h
    std::stack<State*>*  states;
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit;
    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;

    //where your mouse is per view.. it follows the mouse position and changes view///
    sf::Vector2f mousePosView;


    //resources
    std::vector<sf::Texture*> textures;

    virtual void initKeyBinds() = 0;
public:
    //virtual int statenumber(); //to decide what the current state is for Game
    const bool& getQuit() const;
    virtual void updateInput(const float& dt) = 0;
    State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys,std::stack<State*>*  states);
    virtual ~State();
    virtual void updateMousePositions();
    virtual void checkForQuit();
    virtual void endState() = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;

};


#endif //CSCI437_STATE_H
