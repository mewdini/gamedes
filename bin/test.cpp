#include <SFML/Graphics.hpp>
#include "Game.h"
#include "PlayerView.h"
#include "Stage.h"

int main(int argc, char** argv){
    PlayerView* pView = new PlayerView();
    Stage stage(7);

    pView->init();
    pView->createBG(stage.getMap());
    while(pView->getWindow()->isOpen()){
        pView->drawBG();
    }
}