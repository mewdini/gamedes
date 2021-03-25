#include "Stage.h"
#include <SFML/Graphics.hpp>
Stage::Stage(void)
{
};

int* Stage::getMap(){
    return Stage::map;
}
void Stage::draw(sf::RenderWindow &window){
    //draw the terrain and road
    //draw character
    //draw defense towers
    //draw enemies
    //draw components, (gold,remaining enemies,texts)
    //draw effects (of attacks)
};

int Stage::getGold(){
    return gold;
};

void Stage::setGold(int g){
    Stage::gold=g;
};
int Stage::getValueOnMap(int x,int y){
    return Stage::map[x*10+y];
}
void Stage::build(/* Defense defense*/){    //If the player clicks on a slot, the position of the slot should be defense object
    //Stage::gold-=defense.getCost();
    //dposx=defense.getx();
    //dposy=defense.gety();
    /*for(int i=0;i<defensewidth;i++){
        for(int j=0;j<defenseheight;j++){
            Stage::map[i][j]= some number that represent this slot is being used
        }
    }*/
};
