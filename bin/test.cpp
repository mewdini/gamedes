#include <SFML/Graphics.hpp>
#include "Game.h"
#include "PlayerView.h"
#include "Stage.h"

int main(int argc, char** argv){
    PlayerView* pView = new PlayerView();
    Stage stage(7);
    Event event;

    pView->init();
    pView->createBG(stage.getMap());
    while(pView->getWindow()->isOpen()){
        pView->drawBG();
        pView->getWindow()->display();
        while(pView->getWindow()->waitEvent(event)){
            if (event.type == sf::Event::Closed){
                pView->getWindow()->close();
            }
        }
    }
}