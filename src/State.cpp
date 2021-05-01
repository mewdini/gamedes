//
// Created by M on 4/28/21.
//

#include "State.h"

State::State(sf::RenderWindow* window,std::map<std::string, int>* supportedKeys, std::stack<State*>*  states)
{
    this->window = window;
    this->supportedKeys = supportedKeys;
    this->states = states;
    this->quit = false;
}

State::~State()
{

}

const bool& State::getQuit() const
{
    return this->quit;
}

void State::checkForQuit()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("Close"))))
    {
        this->quit = true;
    }

}

void State::endState()
{


}

//gets mouse position
void State::updateMousePositions()
{
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);

    //moves your view depending on coordintes
    this->mousePosView = this->window->mapPixelToCoords(sf::Mouse::getPosition(*this->window));

}
