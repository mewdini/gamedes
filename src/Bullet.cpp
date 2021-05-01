#include "Bullet.h"

Bullet::Bullet(float posX, float posY, int left, int top, int width, int height, Virus newTarget) : SpriteActor(posX, posY, left, top, width, height){
    // Uses spriteactor's const and adds value for the virus bullet is traveling towards
    target = newTarget;
}

void Bullet::follow(){
    // Current calcs assume bullet and virus are 20x20
    // calculates center of target
    float centerX = target.getLocationX()+10;
    float centerY = target.getLocationY()+10;

    // calculates center of self
    float currentX = this->getLocationX()+10;
    float currentY = this->getLocationY()+10;

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
    else(currentY - centerY < -3){
        offsetY = 6;
    }
    else{
        offsetY = 0;
    }
    this->move(offsetX, offsetY);
}

bool Bullet::detectHit(){
    // Current calcs assume bullet and virus are 20x20
    // Detects if bullet overlaps target virus, returns true if yes and false if no

    // Checks for x overlap, if there is an overlap checks for y overlap, if both exist returns true
    if((this->getLocationX() <= target.getLocationX()+20 && this->getLocationX() >= target.getLocationX()) ||
    (this->getLocationX()+20 >= target.getLocationX() && this->getLocationX()+20 <= target.getLocationX()+20)){
        if((this->getLocationY() <= target.getLocationY()+20 && this->getLocationY() >= target.getLocationY()) ||
        (this->getLocationY()+20 >= target.getLocationY() && this->getLocationY()+20 <= target.getLocationY()+20)){
            return true;
        }
    }
    return false;
}