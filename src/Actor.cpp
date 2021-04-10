// Updated by Zack on 4/10
#include "Actor.h"

Actor::Actor(){
    // Default constructor
    gridX = 0;
    gridY = 0;
}

Actor::Actor(int x, int y){
    gridX = x;
    gridY = y;
}

int Actor::getGridX(){
    return gridX;
}

void Actor::setGridX(int x){
    gridX = x;
}

int Actor::getGridY(){
    return gridY;
}

void Actor::setGridY(int y){
    gridY = y;
}
