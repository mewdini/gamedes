//Edited by Zack on 4/10

#ifndef PlayerView_h
#define PlayerView_h
#include <SFML/Graphics.hpp>
#include "SpriteActor.h"
class PlayerView{

    public:
        PlayerView();
        void init();
        void createBG(int*);
        void drawBG();
        void update();
    private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Texture texture;
        SpriteActor* background;

};

#endif