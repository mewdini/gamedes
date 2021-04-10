//Edited by Yixuan Xu on 02/28


#ifndef _STAGE_H_
#define _STAGE_H_

#include <SFML/Graphics.hpp>

class Stage{
    public:
        Stage();
        Stage(int, int);
        //void StartStage();
        int getGold();
        void setGold(int g);
        int* getMap();
        void build(/*Tower tower*/);        //trigger build event
        int getValueOnMap(int x,int y);
        void setValueOnMap(int x, int y, int v);
        void allAttack();
    
    protected:
        int width;
        int height;
        int level;
        //int difficulty;
        int map[width][height];             //might need to import the size of screen from other files instead of hardcoding
        std::list<Enemy*> enemy_list;       //the list of enemies/towers for this level
        std::list<Tower*> tower_list;
        //void attackFirstEnemy();          //choose the enemy to attack   
        //void updateTowers();              //check all towers if they can attack an enemy
        int gold;                           //used to build defense, increase when enemies are killed (maybe has a static growth rate)
        int start1;                         //where enemies are spawned
        int start2;
        int tower_count;
        int cur_tower = 0;
        int enemy_count;
        int cur_enemy = 0;

        //Player player;
        //Enemy? 
    
};


#endif /* _STAGE_H_ */