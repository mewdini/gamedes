//Edited by Yixuan Xu on 04/10


#ifndef _STAGE_H_
#define _STAGE_H_

#include <SFML/Graphics.hpp>
<<<<<<< HEAD
#include <list>

class Stage {
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
        int map;             //might need to import the size of screen from other files instead of hardcoding
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
=======
#include <Virus.h>
#include <Tower.h>
class Stage{
    public:
    Stage(void);
    void draw(sf::RenderWindow &window);
    //void StartStage();
    int getGold();
    void setGold(int g);
    int* getMap();
    void build(/*Tower tower*/);        //trigger build event
    int getValueOnMap(int x,int y);
    void setValueOnMap(int x, int y, int v);
    void allAttack();
    bool build(/*Tower1 tower, int posx,int posy */);
    protected:
    int width;
    int height;
    int level;
    //int difficulty;
    int* map;                           //might need to import the size of screen from other files instead of hardcoding
    int towercount=20;
    int enemycount=100;
    int curtower=0;
    int curenemy=0;
    Virus viruslist[Stage::enemycount];                 //the list of enemeies/towers for this level
    Tower towerlist[20];
    void attackFirstEnemy();          //choose the enemy to attack   
    void updateTowers();              //check all towers if they can attack an enemy
    int gold;                           //used to build defense, increase when enemies are killed (maybe has a static growth rate)
    int start1;                         //where enemies are spawned
    int start2;
    
    
    
>>>>>>> JerrySprint2
};


#endif /* _STAGE_H_ */