//Edited by Yixuan Xu on 04/10


#ifndef _STAGE_H_
#define _STAGE_H_

class Stage;
class Tower;
class Virus;

#include <SFML/Graphics.hpp>
#include "Virus.h"
#include "Tower.h"
#include <math.h>

#include <list>
#include <iostream>
using namespace std;
using namespace sf;

class Stage {
    public:
        Stage();
        Stage(int); // Just for testing
        Stage(int, int);
        //void StartStage();
        int getGold();
        void setGold(int);
        int* getMap();
        int getValueOnMap(int , int);
        void setValueOnMap(int, int, int);
        void allAttack();
        std::list<Tower*>* getTowerList();
        std::list<std::pair<Virus*, sf::Int64>*>* getVirusList();
        void update(sf::Int64);
        bool build(int, int, int);
    protected:
        int width;
        int height;
        int level;
        //int difficulty;
        int map[192];                           //might need to import the size of screen from other files instead of hardcoding
        int tower_count;
        int virus_count;
        std::list<Tower*> tower_list;
        std::list<std::pair<Virus*, Int64>*> virus_list;                 //the list of enemies/towers for this level
        void attackFirstVirus(Tower*);          //choose the enemy to attack
        void updateTowers();              //check all towers if they can attack an enemy
        void spawnVirus();
        
        int gold;                           //used to build defense, increase when enemies are killed (maybe has a static growth rate)
        int start1;                         //where enemies are spawned
        int start2;
        sf::Vector2i base_loc;
        sf::Int64 virus_timer=0;  
        std::list<std::pair<Virus*, Int64>*>::iterator cur_virus_pair;
        //cur_virus_pair
};

#endif /* _STAGE_H_ */
