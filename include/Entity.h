//
// Created by M on 4/29/21.
//

#ifndef CSCI437_ENTITY_H
#define CSCI437_ENTITY_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stack>
#include <vector>
#include "fstream"
#include "sstream"
#include <map>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Entity {

private:

protected:
    sf::RectangleShape shape;
    float movementSpeed;

public:
    Entity();
    virtual ~Entity();


    //functions
    virtual void move(const float& dt, const float dir_x, const float dir_y);
    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};


#endif //CSCI437_ENTITY_H
