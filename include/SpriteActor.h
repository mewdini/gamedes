//Edited by Zack on 4/10
#ifndef SpriteActor_h
#define SpriteActor_h
#include <SFML/Graphics.hpp>
#include "Actor.h"

/* SpriteActor inherits from Actor, and additionally stores a rectangle that will be used for
    displaying a sprite. Methods allow for moving/tracking the location of the rectangle within
    the renderwindow
*/

class SpriteActor : public Actor{

    public:
        SpriteActor();
        SpriteActor(float, float, int, int, int, int);
        float getLocationX();
        float getLocationY();
        void setViewLocation(int, int);
        void setViewDimensions(int, int);
        void move(float, float);
        void setTexture(sf::Texture);
        sf::Sprite getSprite();

    protected:
        sf::Sprite sprite;
        sf::IntRect textureRect;


};

#endif