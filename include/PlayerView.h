//Edited by Zack on 4/10

#ifndef PlayerView_h
#define PlayerView_h
#include <SFML/Graphics.hpp>
#include "SpriteActor.h"
#include "Virus.h"
#include "Tower.h"
#include "Stage.h"


class PlayerView{

    public:
        PlayerView();
        void init();
        void createBG(int*);
        void drawBG();
        void drawTowers(std::list<Tower*>);
        void drawViruses(std::list<Virus*>);
        void update(Stage);
    private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Texture texture;
        SpriteActor* background;

};

#endif