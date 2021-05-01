#include "Stage.h"
#include <SFML/Graphics.hpp>

// Zack - Removed a bunch of ; at end of methods

Stage::Stage()
{
    height = 16;
    width = 12;
    map[192];
    tower_count = 20;
    virus_count = 100;
    cur_virus_pair = virus_list.begin();
}

Stage::Stage(int x){
    // Test to set up first stage
    height = 16;
    width = 12;
    //initialize map, use 0 for background, 1 for base, 3 for tower positions, 4 for built towers， 5 for north-south path, 6 for east-west path, 7 for corner connecting south-east path, 8 for " south-west, 9 for " north-east, 10 for " north-west
    int map_values[192] = {0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,7,6,6,6,6,6,6,8,0,0,0,0,0,0,0,0,5,3,0,0,0,0,3,5,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,0,0,0,0,0,
    0,0,0,5,3,0,0,0,0,3,5,0,0,0,0,0,0,0,0,5,0,0,0,1,0,0,5,0,0,0,7,6,0,0,0,5,0,0,0,5,0,0,5,0,0,0,5,3,0,0,0,5,0,0,0,5,0,3,5,3,0,3,5,0,0,0,0,5,3,0,3,5,0,0,9,6,6,6,10,0,0,0,0,9,6,6,6,10,0,0,0,0,3,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    std::copy(std::begin(map_values), std::end(map_values), std::begin(map));
    tower_count = 20;
    virus_count = 100;
    cur_virus_pair = virus_list.begin();
    start1 = 15;
    start2 = 6;
    // use malloc if these are local variables?
    // populate virus list
    for (int i = 0; i < virus_count; i++) {
        auto temp_virus = Virus(start1, start2, Left, Virus::Viruses::covid, 13, this);
        auto temp_pair = std::pair<Virus*, sf::Int64>(&temp_virus, 1000000);
        virus_list.push_back(&temp_pair);
    }
    base_loc = Vector2i(7,6);
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
    return true;

}

void Stage::attackFirstVirus(Tower* tower){  //x,y are coordinates of the tower, and r is the range of the tower
    for (auto const& virus : virus_list) {
        Virus* enemy = virus->first;
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

std::list<Tower*>* Stage::getTowerList()
{
    return &tower_list;
}

std::list<std::pair<Virus*, Int64>*>* Stage::getVirusList()
{
    return &virus_list;
}

void Stage::update(Int64 elapsedTime)
{
    // check if time to spawn virus
    virus_timer += elapsedTime;
    if ((virus_timer >= (*cur_virus_pair)->second) && (virus_count > 0)) {
        spawnVirus();
        virus_timer = 0;
    }

    // update all viruses
    for (auto const& pair : virus_list) {
        pair->first->update(elapsedTime);
    }

    // update all towers
    for (auto const& tower : tower_list) {
        tower->Update(elapsedTime);
    }
}

void Stage::spawnVirus() {
    (*cur_virus_pair)->first->setAlive(true);
    cur_virus_pair++;
    virus_count--;
}

Vector2i Stage::pixelToGrid(Vector2f pixel_pos)
{
    Vector2i grid_pos;
    grid_pos.x = floor(pixel_pos.x / 50);
    grid_pos.y = floor(pixel_pos.y / 50);
    return grid_pos;
}

// gets pixel coords of middle of grid square
Vector2f Stage::gridToPixelMiddle(Vector2i grid_pos)
{
    Vector2f mid;
    mid.x = grid_pos.x * 50 + 25;
    mid.y = grid_pos.y * 50 + 25;
    return mid;
}