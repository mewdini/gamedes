#include "Player.h"

// default constructor
Player::Player() {
    setOriginX(0);
    setOriginY(0);
};

// constructor
Player::Player(/*Weapon w*/float x, float y, float vel) {
    //Player::weapon=w;
    setOriginX(x);
    setOriginY(y);
};