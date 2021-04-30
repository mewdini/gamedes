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
    cur_virus_pair = virus_list.begin();
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
    cur_virus_pair = virus_list.begin();
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
    return true;

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

std::list<Tower*>* Stage::getTowerList()
{
    return &tower_list;
}

std::list<Virus*>* Stage::getVirusList()
{
    return &virus_list;
}

void Stage::update(sf::Int64 elapsedTime)
{
    // check if time to spawn virus
    virus_timer += elapsedTime;
    if (virus_timer >= curr_virus_pair.second && virus_count > 0) {
        spawnVirus(start1, start2, curr_virus_pair.first, 13);
        curr_virus_pair++;
        virus_timer = 0;
        virus_count--;
    }

    // update all viruses
    for (auto const& virus : virus_list) {
        virus->update(elapsedTime, base_loc);
    }

    // update all towers
    for (auto const& tower : tower_list) {
        tower->Update(elapsedTime);
    }
}

void Stage::spawnVirus(float startX, float startY, Virus::Viruses type, int seed)
{
    switch(type)
    {
        case Virus::Viruses::covid:
            //Covid Virus
            //this m_Sprite variable will pull the sprite of the Zombie
            //We should probably create a TextureHolder Class from where we
            // load it
            m_Texture.loadFromFile("../data/coronavirus_0.png");
            m_Sprite.setTexture(m_Texture);
            m_Sprite.setOrigin(15, 6);
            m_Speed = COVID_VIRUS_SPEED;
            m_Health = COVID_VIRUS_HEALTH;
            break;

        case Virus::Viruses::resistant:
            // Resistant Strain
            // m_Sprite = Sprite(TextureHolder)
            m_Speed = RESISTANT_STRAIN_SPEED;
            m_Health = RESISTANT_STRAIN_HEALTH;
            break;

        case Virus::Viruses::contagious:
            // Contagious Strain
            // m_Sprite = Sprite(TextureHolder)
            m_Speed = CONTAGIOUS_STRAIN_SPEED;
            m_Health = CONTAGIOUS_STRAIN_HEALTH;
            break;

        case Virus::Viruses::airborn:
            // Airborn Strain
            // m_Sprite = Sprite(TextureHolder)
            m_Speed = AIRBORN_STRAIN_SPEED;
            m_Health = AIRBORN_STRAIN_HEALTH;
            break;

        case Virus::Viruses::coughing:
            // Coughing Strain
            // m_Sprite = Sprite(TextureHolder)
            m_Speed = COUGHING_PERSON_SPEED;
            m_Health = COUGHING_PERSON_HEALTH;
            break;
    }

    m_Alive = true;

    //Every virus has a unique speed
    srand((int)time(0) * seed);
    float modifier = (rand() % MAX_VARIANCE) + OFFSET;
    modifier /= 100;  //it will equal between .7 and 1
    m_Speed *= modifier;

    // Location of the virus
    m_Position.x = startX;
    m_Position.y = startY;
    //Setting origin
    //m_Sprite.setOrigin(location);
    //m_Sprite.setPosition(m_Position);
}