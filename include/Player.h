//Edited by Yixuan Xu on 02/28

#ifndef _PLAYER_H_
#define _PLAYER_H_

class Player{
    public:
    Player();
    Player(/*Weapon w*/int x,int y, int s); //x,y position and speed 
    void movePlayer(int a); //trigger move event Are we creating a Direction class or should we just use numbers?
    void attack();     //trigger attack event
    
    private:
    //Weapon weapon;
    //Graphics avatar ;
    int posx;   //position
    int posy;
    int speed;
};





#endif /* _PLAYER_H_ */