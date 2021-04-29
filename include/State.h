//
// Created by M on 4/28/21.
//

#ifndef CSCI437_STATE_H
#define CSCI437_STATE_H

//#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <vector>
#include "fstream"
#include "sstream"

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>


class State
{

private:
    sf::RenderWindow* window;
    std::vector<sf::Texture*> textures;
public:
    State(sf::RenderWindow* window);
    virtual ~State();
    virtual void endState() = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;

};


#endif //CSCI437_STATE_H
