#include "Player.h"
#include "Actor.h"

// default constructor
Player::Player() {
    setGridX(0);
    setGridY(0);
};

// constructor
Player::Player(/*Weapon w*/float x, float y, float vel) {
    //Player::weapon=w;
    setGridX(x);
    setGridY(y);
};