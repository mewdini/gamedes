//Edited by Zack on 4/10
#ifndef BlockActor_h
#define BlockActor_h
#include <SFML/Graphics.hpp>

/* BlockActor inherits from Actor, and additionally stores a rectangle that will be used for
    displaying a sprite. Methods allow for moving/tracking the location of the rectangle within
    the renderwindow
*/

class BlockActor : public Actor{

    public:
        BlockActor();
        BlockActor(float, float, int, int, int, int);
        float getLocationX();
        float getLocationY();
        void setViewLocation(int, int);
        void setViewDimensions(int, int);
        void move(float, float);
        void setTexture(sf::Texture);

    private:
        sf::Sprite sprite;


};

#endif