// Updated by Zack on 3/1

#define _USE_MATH_DEFINES
#include <cmath>
#include "DynamicActor.h"

// BUG will probably teleport velocity length in direction of destination
// TODO change info on grid (is necessary for USA map?)
// BUG stop early if supposed to move beyond destination
void DynamicActor::move(float deltaX, float deltaY){
    // get x and y vel
    float xPos = deltaX - this->getOriginX();
    float yPos = deltaY - this->getOriginY();
    float theta = std::atan(xPos/yPos) * 180 / M_PI;
    float xVel = 2 * std::sin(theta) * 180 / M_PI;
    float yVel = 2 * std::cos(theta) * 180 / M_PI;

    // move that many units in each direction
    float xFinal = this->getOriginX() + xVel;
    float yFinal = this->getOriginY() + yVel;
    
    this->setOriginX(xFinal);
    this->setOriginY(yFinal);
}