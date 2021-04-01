//Edited by Yixuan Xu on 02/28

#include <DynamicActor.h>

#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player : public DynamicActor {
    public:
    Player();
    Player(/*Weapon w*/float x, float y, float v); //x,y position and speed 
    void movePlayer(float, float); //trigger move event (global x and y)
};





#endif /* _PLAYER_H_ */