#include <SFML/Graphics.hpp>
#include "Game.h"
#include "PlayerView.h"
#include "Stage.h"

int main(int argc, char** argv){
    PlayerView pview();
    Stage stage(7);

    pView.init();
    pView.createBG(stage.getMap());
    pView.drawBG();
}