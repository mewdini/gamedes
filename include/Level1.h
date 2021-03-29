//Edited by Yixuan Xu on 03/24
#include "Stage.h"

#ifndef _LEVEL1_H_
#define _LEVEL1_H_

class Level1: public Stage{
    public:
    Level1():Stage(){

    };
    void startLevel1();
    private:
    void spawnEnemy();
    int startGold=100;
    //int objects[];
};

#endif