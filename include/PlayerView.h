//Edited by Zack on 4/10

#ifndef PlayerView_h
#define PlayerView_h
#include <SFML/Graphics.hpp>
class PlayerView{

    public:
        PlayerView();
        void init();
        void drawBG(int*);
        void update();
    private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Texture texture;
        BlockActor* background;

};

#endif