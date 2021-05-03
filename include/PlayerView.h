//Edited by Zack on 4/10

#ifndef PlayerView_h
#define PlayerView_h
#include <SFML/Graphics.hpp>
#include "SpriteActor.h"
#include "Virus.h"
#include "Tower.h"
#include "Stage.h"
#include <list>


class PlayerView{

    public:
        
        PlayerView();
        void init();
        void createBG(int*);
        void drawBG(sf::RenderWindow* window);
        void drawTowers(std::list<Tower*>);
        void drawViruses(std::list<std::pair<Virus*, sf::Int64>*>*);
        //void update(Stage); omitted for testing
        sf::RenderWindow* getWindow();
        bool isButtonPressed(sf::Mouse::Button);
        sf::Vector2i getMousePos();
        sf::Texture getTexture(); // Will need copies if multiple textures used
        void setTexture(sf::Texture);

    private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Texture texture;
        SpriteActor background[192];

};

#endif