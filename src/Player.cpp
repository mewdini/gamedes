#include "Player.h"

// default constructor
Player::Player() {
    this->setOriginX(0);
    this->setOriginY(0);
};

// constructor
Player::Player(/*Weapon w*/float x, float y, float vel) {
    //Player::weapon=w;
    this->setOriginX(x);
    this->setOriginY(y);
};