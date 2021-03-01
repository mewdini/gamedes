// Updated by Zack on 3/1
#include "Actor.h"

int Actor::getOriginX(){
    return origin.x;
}

void Actor::setOriginX(int newX){
    origin.x = newX;
}

int Actor::getOriginY(){
    return origin.y;
}

void Actor::setOriginY(int newY){
    origin.y = newY;
}
