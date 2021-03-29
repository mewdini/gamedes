//Edited by Yixuan Xu on 02/28


#ifndef _STAGE_H_
#define _STAGE_H_

#include <SFML/Graphics.hpp>

class Stage{
    public:
    Stage(void);
    void draw(sf::RenderWindow &window);
    //void StartStage();
    int getGold();
    void setGold(int g);
    int* getMap();
    void build(/*Defense defense*/);      //trigger build event
    int getValueOnMap(int x,int y);
    protected:
    int width;
    int height;
    int level;
    //int difficulty;
    int* map;      //might need to import the size of screen from other files instead of hardcoding
    int* enemylist;         //the list of enemeies for this level
    int gold;                //used to build defense, increase when enemies are killed (maybe has a static growth rate)
    //Character player;
    //Enemy? 
    
};


#endif /* _STAGE_H_ */