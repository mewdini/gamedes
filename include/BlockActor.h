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
        BlockActor(int, int, int, int);
        int getLocationX();
        int getLocationY();
        void move(float, float);

    private:
        sf::RectangleShape block;


};

#endif