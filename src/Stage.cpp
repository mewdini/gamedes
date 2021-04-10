#include "Stage.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

Stage::Stage()
{
    this->height = 16;
    this->width = 12;
    this->map[192];
    this->tower_count = 20;
    this->virus_count = 100;
    this->cur_tower, this->cur_enemy = 0;
};

Stage::Stage(int x, int y)
{
    this->width = x;
    this->heigth = y;
    this->map[this->width*this->height];
}

int* Stage::getMap()
{
    return this->map;
}

int Stage::getGold()
{
    return this->gold;
};

void Stage::setGold(int g)
{
    this->gold = g;
};
int Stage::getValueOnMap(int x,int y){          //inputs are coordinates on the map, top-left is (0,0)
    return this->map[y * this->width + x];
}
void Stage::setValueOnMap(int x, int y, int v){
    this->map[y * this->width + x] = v;
}
bool Stage::build(first, int posx,int posy ){    //If the player clicks on a slot, the position of the slot should be defense object
    if(this->map[posx + this->width * posy] != 3){
        return false;   //position is not valid;
    }
    if(this->gold < this->tower.getCost()){
        return false;
    }
    this->gold -= this->tower.getCost();
    
    this->setValueOnMap(posx,posy,4);
    //determine by enum 
    this->towerlist[cur_tower] = Tower(posx,posy,1);
    this->cur_tower++;
    return true;

};
void Stage::spawnVirus()
{
    if (this->cur_virus < this->virus_count)
    {
        Virus* enemy = this->virus_list[this->cur_virus];
        enemy->setAlive();
        enemy->spawn(this->startx,this->starty,0,13);
        this->cur_virus++;
    };
};

void Stage::attackFirstVirus(Tower* tower){  //x,y are coordinates of the tower, and r is the range of the tower 
    for(int i = 0; i < enemy_count; i++){
        Virus* enemy = this->virus_list[i];
        if(!enemy->isAlive()){
            posx = enemy->getx();
            posy = enemy->gety();
            x = this->tower->getx();
            y = this->tower->gety();
            r = this->tower->getRange();
            if ((posx-x)*(posx-x)+(posy-y)*(posy-y)<=r*r)
            {
                this->tower->attack(enemy);
            }
        }
    }
}

void Stage::updateTowers(){
    for(int i = 0; i < this->cur_tower; i++){
        
            Tower* tower = this->tower_list[i];
            this->attackFirstEnemy(tower);
        
    }
}

