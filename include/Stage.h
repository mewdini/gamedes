//Edited by Yixuan Xu on 04/10


#ifndef _STAGE_H_
#define _STAGE_H_

#include <SFML/Graphics.hpp>
#include "Tower.h"
#include "Virus.h"

#include <list>
#include <iostream>
using namespace std;
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
        bool build(Tower::Towers, int, int);
        std::list<Tower*>* getTowerList();
        std::list<Virus*>* getVirusList();
        void update(sf::Int64);
    protected:
        int width;
        int height;
        int level;
        //int difficulty;
        int map[192];                           //might need to import the size of screen from other files instead of hardcoding
        int tower_count;
        int virus_count;
        std::list<std::pair<Virus::Viruses, sf::Int64>>::iterator cur_virus_pair;
        std::list<Tower*> tower_list;
        std::list<std::pair<Virus::Viruses, sf::Int64>*> virus_list;                 //the list of enemies/towers for this level
        void attackFirstVirus(Tower*);          //choose the enemy to attack
        void updateTowers();              //check all towers if they can attack an enemy
        void spawnVirus(float, float, Virus::Viruses, int);
        sf::Int64 virus_timer;
        int gold;                           //used to build defense, increase when enemies are killed (maybe has a static growth rate)
        int start1;                         //where enemies are spawned
        int start2;
        Vector2f base_loc;
};

#endif /* _STAGE_H_ */
