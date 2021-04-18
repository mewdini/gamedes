#include "Stage.h"
#include "Game.h"
#include <SFML/Graphics.hpp>

// Zack - Removed a bunch of ; at end of methods

Stage::Stage()
{
    height = 16;
    width = 12;
    map[192];
    tower_count = 20;
    virus_count = 100;
    cur_tower = tower_list.begin();
    cur_virus = virus_list.begin();
}

Stage::Stage(int x){
    // Test to set up first stage
    height = 16;
    width = 12;
    int map_values[192] = {0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,7,6,6,6,6,6,6,8,0,0,0,0,0,0,0,0,5,3,0,0,0,0,3,5,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,0,0,0,0,0,
    0,0,0,5,3,0,0,0,0,3,5,0,0,0,0,0,0,0,0,5,0,0,0,1,0,0,5,0,0,0,7,6,0,0,0,5,0,0,0,5,0,0,5,0,0,0,5,3,0,0,0,5,0,0,0,5,0,3,5,3,0,3,5,0,0,0,0,5,3,0,3,5,0,0,9,6,6,6,10,0,0,0,0,9,6,6,6,10,0,0,0,0,3,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::copy(std::begin(map_values), std::end(map_values), std::begin(map));
    tower_count = 20;
    virus_count = 100;
    cur_tower = tower_list.begin();
    cur_virus = virus_list.begin();
    start1 = 15;
    start2 = 6;
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
}

void Stage::setGold(int g)
{
    gold = g;
}
int Stage::getValueOnMap(int x,int y){          //inputs are coordinates on the map, top-left is (0,0)
    return map[y * width + x];
}
void Stage::setValueOnMap(int x, int y, int v){
    map[y * width + x] = v;
}
bool Stage::build(Tower::Towers tower, int posx, int posy ){    //If the player clicks on a slot, the position of the slot should be defense object
    if(map[posx + width * posy] != 3){
        return false;   //position is not valid;
    }
    int tower_cost;
    switch (tower)
    {
        case Tower::Towers::first:
            tower_cost = 100;
            break;
    }

    if(gold < tower_cost){
        return false;
    }

    gold -= tower_cost;
    
    setValueOnMap(posx,posy,4);

    //determine by enum
    Tower new_tower = Tower(posx,posy,tower);
    tower_list.push_back(&new_tower);
    cur_tower++;
    return true;

}
void Stage::spawnVirus()
{
    if (virus_count > 0)
    {
        Virus* enemy = *cur_virus;
        enemy->spawn(start1,start2,0,13);
        cur_virus++;
        virus_count--;
    };
}

void Stage::attackFirstVirus(Tower* tower){  //x,y are coordinates of the tower, and r is the range of the tower
    for (auto const& enemy : virus_list) {
        if(enemy->isAlive()){
            auto virus_pos = enemy->getPosition();
            float posx = virus_pos.x;
            float posy = virus_pos.y;
            auto tower_pos = tower->GetPosition();
            float x = tower_pos.x;
            float y = tower_pos.y;
            float r = tower->GetRadius();
            if ((posx-x)*(posx-x)+(posy-y)*(posy-y)<=r*r)
            {
                tower->Attack(enemy);
            }
        }
    }
}

void Stage::updateTowers(){
    for (auto const& tower : tower_list) {
        attackFirstVirus(tower);
    }
}

std::list<Tower*>* Stage::getTowerList()
{
    return &tower_list;
}

std::list<Virus*>* Stage::getVirusList()
{
    return &virus_list;
}

// TODO make towers attack at different speeds
void Stage::allAttack()
{
    for (auto const& tower : tower_list) {
        attackFirstVirus(tower);
    }
}