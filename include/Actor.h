//Edited by Zack on 3/1
#ifndef Actor_h
#define Actor_h
#include <SFML/Graphics.hpp>

/* Basic idea is that an origin point is only thing common to all rendered objects. Will
    need to discuss how exactly objects are rendered but drawing shapes based on an origin
    to form our player and enemy models seems like a relatively easy solution

    No constructor, assuming origin will be initialized by more specific constructor down the line
*/

class Actor{

    public:
        int getOriginX();
        void setOriginX(int);
        int getOriginY();
        void setOriginY(int);

    private:
        sf::Vector2f origin;

};

#endif