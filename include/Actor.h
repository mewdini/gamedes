//Edited by Zack on 4/10

#include <SFML/Graphics.hpp>

#ifndef Actor_h
#define Actor_h

/* Actor store and has get/set methods for the location of the object on the map grid
*/

class Actor{
    public:
        Actor();
        Actor(int, int);
        int getGridX();
        void setGridX(int);
        int getGridY();
        void setGridY(int);

    protected:
        int gridX;
        int gridY;
        sf::Shape shape;
};

#endif