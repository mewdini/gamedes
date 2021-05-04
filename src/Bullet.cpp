#include "Bullet.h"

Bullet::Bullet(){
    // default const, shouldn't be used
    // Default sets active to false, changes to true by tower when creating a bullet with other params
    active = false;
}

Bullet::Bullet(float posX, float posY, int left, int top, int width, int height, Virus* newTarget, float* newDamage){
    // Dupes spriteactor's const and adds value for the virus bullet is traveling towards
    sprite.setPosition(posX, posY);
    textureRect = sf::IntRect(left, top, width, height);
    sprite.setTextureRect(textureRect);
    target = newTarget;
    damage = newDamage;
    active = true;
}

void Bullet::follow(Int64 delta){
    if(active){
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
        // Arbitraily decided to make base speed of bullets 50px?, may need to change
        if(currentX - centerX > 3){
            offsetX = -(50 * (f_delta / C));
        }
        else if(currentX - centerX < -3){
            offsetX = 50 * (f_delta / C);
        }
        else{
            offsetX = 0;
        }

        if(currentY - centerY > 3){
            offsetY = -50 * (f_delta / C);
        }
        else if(currentY - centerY < -3){
            offsetY = 50 * (f_delta / C);
        }
        else{
            offsetY = 0;
        }
        move(offsetX, offsetY);
    }
}

bool Bullet::detectHit(){
    // Current calcs assume bullet is 20x20 and virus is 50x50
    // Detects if bullet overlaps target virus, returns true if yes and false if no

    if(active){
        //right side of bullet overlaps left side of virus
        if(getLocationX()+20 >= target->getLocationX()+8 && getLocationX()+20 <= target->getLocationX()+42 && detectYOverlap()){
            target->hit(*damage);
            active = false;
            return true;
        }
        // left side of bullet overlaps right side of virus
        else if(getLocationX() <= target->getLocationX()+42 && getLocationX() >= target->getLocationX()+8 && detectYOverlap()){
            target->hit(*damage);
            active = false;
            return true;
        }
    }

    // If neither, returns false
    return false;
}

bool Bullet::detectYOverlap(){
    // Checks if bottom of bullet is below top of virus or top of bullet is above bottom of virus
    return (getLocationY()+20 >= target->getLocationY()+8 || getLocationY() <= target->getLocationY()+42);
}

bool Bullet::isActive(){
    return active;
}
