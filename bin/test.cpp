#include <SFML/Graphics.hpp>
#include "Game.h"
#include "PlayerView.h"
#include "Stage.h"

int main(int argc, char** argv){
    PlayerView* pView = new PlayerView();
    Stage stage(7);
    Event event;

    /* Created a sprite to display, shows up correctly while everything else is white
    sf::Texture text;
    text.loadFromFile("..\\data\\ThirdSpriteSheet.png");
    pView->setTexture(text);
    sf::IntRect box(0, 0, 50, 50);
    sf::Sprite sprite(pView->getTexture(), box);
    */

    pView->init();
    pView->createBG(stage.getMap());
    while(pView->getWindow()->isOpen()){
        pView->drawBG();
        //pView->getWindow()->draw(sprite);
        pView->getWindow()->display();
        while(pView->getWindow()->waitEvent(event)){
            if (event.type == sf::Event::Closed){
                pView->getWindow()->close();
            }
        }
    }
}