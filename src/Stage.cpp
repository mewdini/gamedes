#include "Stage.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

Stage::Stage()
{
    height = 16;
    width = 12;
    map[192];
    tower_count = 20;
    virus_count = 100;
    cur_tower = tower_list.begin();
    cur_virus = virus_list.begin();
};

Stage::Stage(int x){
    // Test to set up first stage
    this->height = 16;
    this->width = 12;
    this->map[192] = {0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,7,6,6,6,6,6,6,8,0,0,0,0,0,0,0,0,5,3,0,0,0,0,3,5,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,0,0,0,0,0,
    0,0,0,5,3,0,0,0,0,3,5,0,0,0,0,0,0,0,0,5,0,0,0,1,0,0,5,0,0,0,7,6,0,0,0,5,0,0,0,5,0,0,5,0,0,0,5,3,0,0,0,5,0,0,0,5,0,3,5,3,0,3,5,0,0,0,0,5,3,0,3,5,0,0,9,6,6,6,10,0,0,0,0,9,6,6,6,10,0,0,0,0,3,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    this->tower_count = 20;
    this->virus_count = 100;
    this->cur_tower, this->cur_enemy = 0;
}

Stage::Stage(int x, int y)
{
    width = x;
    height = y;
    map[width*height];
}

int* Stage::getMap()
{
    return map;
}

int Stage::getGold()
{
    return gold;
};

void Stage::setGold(int g)
{
    gold = g;
};
int Stage::getValueOnMap(int x,int y){          //inputs are coordinates on the map, top-left is (0,0)
    return map[y * width + x];
}
void Stage::setValueOnMap(int x, int y, int v){
    map[y * width + x] = v;
}
bool Stage::build(Game::Towers tower, int posx, int posy ){    //If the player clicks on a slot, the position of the slot should be defense object
    if(map[posx + width * posy] != 3){
        return false;   //position is not valid;
    }
    int tower_cost;
    switch (tower)
    {
        case Game::Towers::first:
            tower_cost = 100;
            break;
    }

    if(gold < tower_cost){
        return false;
    }

    gold -= tower_cost;
    
    setValueOnMap(posx,posy,4);

    //determine by enum
    *cur_tower = &Tower(posx,posy,1);
    cur_tower++;
    return true;

};
void Stage::spawnVirus()
{
    if (virus_count > 0)
    {
        Virus* enemy = *cur_virus;
        enemy->setAlive();
        enemy->spawn(startx,starty,0,13);
        cur_virus++;
        virus_count--;
    };
};

void Stage::attackFirstVirus(Tower* tower){  //x,y are coordinates of the tower, and r is the range of the tower 
    for(int i = 0; i < enemy_count; i++){
        Virus* enemy = virus_list[i];
        if(!enemy->isAlive()){
            posx = enemy->getx();
            posy = enemy->gety();
            x = tower->getx();
            y = tower->gety();
            r = tower->getRange();
            if ((posx-x)*(posx-x)+(posy-y)*(posy-y)<=r*r)
            {
                tower->attack(enemy);
            }
        }
    }
}

void Stage::updateTowers(){
    for(int i = 0; i < cur_tower; i++){
        
            Tower* tower = tower_list[i];
            attackFirstEnemy(tower);
        
    }
}

std::list<Tower*> Stage::getTowerList()
{
    return tower_list;
}

std::list<Virus*> Stage::getVirusList()
{
    return virus_list;
}