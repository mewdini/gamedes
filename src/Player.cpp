#include "Player.h"

Player::Player(){

};
Player::Player(/*Weapon w*/int x,int y, int s){ //constructor
    //Player::weapon=w;
    Player::posx=x;
    Player::posy=y;
    Player::speed=s;
};

void Player::movePlayer(int a){
    switch (a)
    {
    case 0:         //move up
        posy-=Player::speed;
        break;
    case 1:         //move down
        posy+=Player::speed;
        break;
    case 2:         //move left
        posx-=Player::speed;
        break;
    case 3:         //move right
        posx+=Player::speed;
        break;
    default:
        break;
    }
}

void Player::attack(){
    //trigger event:player attacks
}