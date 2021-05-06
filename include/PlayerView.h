//Edited by Zack on 4/10

#ifndef PlayerView_h
#define PlayerView_h
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "SpriteActor.h"
#include "Virus.h"
#include "Tower.h"
#include "Bullet.h"
#include <list>


class PlayerView{

    public:
        
        PlayerView();
        void init();
        void createBG(int*);
        void drawBG(sf::RenderWindow* window);
        void drawViruses(sf::RenderWindow* window, std::list<std::pair<Virus, Int64>>* pairs);
        void drawBullets(sf::RenderWindow*, std::list<Bullet>*);
        sf::RenderWindow* getWindow();
        bool isButtonPressed(sf::Mouse::Button);
        sf::Vector2i getMousePos();
        sf::Texture* getTexture();
        sf::Texture* getTexture2(); // Will need copies if multiple textures used
        void setTexture(sf::Texture);

    private:
        sf::RenderWindow window;
        sf::Font font;
        sf::Texture texture;
        sf::Texture texture2;
        sf::Music theme;
        sf::Image icon;
        SpriteActor background[192];

};

#endif