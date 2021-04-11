//Edited by Zack on 4/10
#ifndef TextActor_h
#define TextActor_h
#include <SFML/Graphics.hpp>
#include <string>
#include "Actor.h"

/* TextActor inherits from Actor, and additionally stores a text object for displaying text
    on the renderwindow. Methods allow for tracking/moving the text object, and also changing
    the string displayed by the object
*/

class TextActor : public Actor{

    public:
        TextActor(sf::Font, int, int, std::string);
        int getLocationX();
        int getLocationY();
        void move(float, float);
        void setContent(std::string);

    private:
        sf::Text text;


};

#endif