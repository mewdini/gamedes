#include "Bullet.h"

Bullet::Bullet(){
    // default const, shouldn't be used
}

Bullet::Bullet(float posX, float posY, int left, int top, int width, int height, Virus* newTarget, float* newDamage){
    // Dupes spriteactor's const and adds value for the virus bullet is traveling towards
    sprite.setPosition(posX, posY);
    textureRect = sf::IntRect(left, top, width, height);
    sprite.setTextureRect(textureRect);
    target = newTarget;
    damage = newDamage;
}

void Bullet::follow(Int64 delta){

    // Copied delta logic from Virus
    float offsetX, offsetY = 0;
    float f_delta = (float) delta;
    float C = 1000000; // combats delta being in microseconds


    // Current calcs assume bullet is 20x20, virus is 50x50
    // calculates center of target
    float centerX = target->getLocationX()+25;
    float centerY = target->getLocationY()+25;

    // calculates center of self
    float currentX = getLocationX()+10;
    float currentY = getLocationY()+10;

    // Determines relative location and sets movement values to send bullet towards its target 
    // Arbitraily decided to make base speed of bullets 5px, may need to change
    if(currentX - centerX > 3){
        offsetX = -(5 * (f_delta / C));
    }
    else if(currentX - centerX < -3){
        offsetX = 5 * (f_delta / C);
    }
    else{
        offsetX = 0;
    }

    if(currentY - centerY > 3){
        offsetY = -5 * (f_delta / C);
    }
    else if(currentY - centerY < -3){
        offsetY = 5 * (f_delta / C);
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
            target->hit(*damage);
            return true;
        }
    }
    return false;
}

