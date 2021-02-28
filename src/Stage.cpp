#include "Stage.h"

Stage::Stage(void)
{
};

Stage::Stage(int lev,int m[800][600],int list[5],int g){
    Stage::level=lev;
    map[800][600]=m[800][600];
    enemylist[5]=list[5];
    gold=g;


};
void Stage::DisplayStage(){
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
