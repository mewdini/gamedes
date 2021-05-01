#include "Bullet.h"

Bullet::Bullet(float posX, float posY, int left, int top, int width, int height, Virus* newTarget){
    // Uses spriteactor's const and adds value for the virus bullet is traveling towards
    sprite.setPosition(posX, posY);
    textureRect = sf::IntRect(left, top, width, height);
    sprite.setTextureRect(textureRect);
    target = newTarget;
}

void Bullet::follow(){
    // Current calcs assume bullet and virus are 20x20
    // calculates center of target
    float centerX = target->getLocationX()+10;
    float centerY = target->getLocationY()+10;

    // calculates center of self
    float currentX = getLocationX()+10;
    float currentY = getLocationY()+10;

    // Determines relative location and sets movement values to send bullet towards its target
    float offsetX, offsetY;

    if(currentX - centerX > 3){
        offsetX = -6;
    }
    else if(currentX - centerX < -3){
        offsetX = 6;
    }
    else{
        offsetX = 0;
    }

    if(currentY - centerY > 3){
        offsetY = -6;
    }
    else if(currentY - centerY < -3){
        offsetY = 6;
    }
    else{
        offsetY = 0;
    }
    move(offsetX, offsetY);
}

bool Bullet::detectHit(){
    // Current calcs assume bullet and virus are 20x20
    // Detects if bullet overlaps target virus, returns true if yes and false if no

    // Checks for x overlap, if there is an overlap checks for y overlap, if both exist returns true
    if((getLocationX() <= target->getLocationX()+20 && getLocationX() >= target->getLocationX()) ||
    (getLocationX()+20 >= target->getLocationX() && getLocationX()+20 <= target->getLocationX()+20)){
        if((getLocationY() <= target->getLocationY()+20 && getLocationY() >= target->getLocationY()) ||
        (getLocationY()+20 >= target->getLocationY() && getLocationY()+20 <= target->getLocationY()+20)){
            return true;
        }
    }
    return false;
}

