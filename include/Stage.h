//Edited by Yixuan Xu on 04/10


#ifndef _STAGE_H_
#define _STAGE_H_

#include <SFML/Graphics.hpp>
#include "Virus.h"
#include "Tower.h"
#include <math.h>
#include <iterator>
#include <list>
#include <iostream>
using namespace std;
using namespace sf;

class Stage {
    public:
        Stage();
        Stage(Texture*);
        //Stage(int); // Just for testing
        //Stage(int, int);
        //void StartStage();
        int getGold();
        void setGold(int);
        int* getMap();
        int getValueOnMap(int , int);
        void setValueOnMap(int, int, int);
        void allAttack();
        std::list<Tower>* getTowerList();
        bool build(Towers, int, int);
        std::list<std::pair<Virus, Int64>>* getVirusList();
        void update(Int64);
        static Vector2i pixelToGrid(Vector2f);
        static Vector2f gridToPixelMiddle(Vector2i);
        static Vector2f gridToPixelTopLeft(Vector2i);
    protected:
        int width;
        int height;
        int level;
        //int difficulty;
        int map[192] = {0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,7,6,6,6,6,6,6,8,0,0,0,0,0,0,0,0,5,3,0,0,0,0,3,5,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,0,0,0,0,0,
    0,0,0,5,3,0,0,0,0,3,5,0,0,0,0,0,0,0,0,5,0,0,0,1,0,0,5,0,0,0,7,6,0,0,0,5,0,0,0,5,0,0,5,0,0,0,5,3,0,0,0,5,0,0,0,5,0,3,5,3,0,3,5,0,0,0,0,5,3,0,3,5,0,0,9,6,6,6,10,0,0,0,0,9,6,6,6,10,0,0,0,0,3,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};                         //might need to import the size of screen from other files instead of hardcoding
        int tower_count;
        int virus_count;
        std::list<std::pair<Virus, Int64>>::iterator cur_virus_pair;
        std::list<Tower> tower_list;
        std::list<std::pair<Virus, Int64>> virus_list;                 //the list of enemies/towers for this level
        void attackFirstVirus(Tower*);          //choose the enemy to attack
        void updateTowers();              //check all towers if they can attack an enemy
        sf::Int64 virus_timer;
        int gold;                           //used to build defense, increase when enemies are killed (maybe has a static growth rate)
        int start1;                         //where enemies are spawned
        int start2;
        sf::Vector2i base_loc;
        void spawnVirus();
        Texture virus_tex;
};

#endif /* _STAGE_H_ */
