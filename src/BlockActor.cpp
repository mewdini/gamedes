// Updated by Zack on 4/10
#include "BlockActor.h"

BlockActor::BlockActor(){
    block.setPosition(0,0);
}

BlockActor::BlockActor(float posX, float posY){
    block.setPosition(posX, posY);
}

int BlockActor::getLocationX(){
    return block.getPosition().x;
}

int BlockActor::getLocationY(){
    return block.getPosition().y;
}

void BlockActor::setViewLocation(int x, int y){
    view.left = x;
    view.top = y;
}

void BlockActor::setViewDimensions(int width, int height){
    view.width = width;
    view.height = height;
}

void BlockActor::move(float deltaX, float deltaY){
    block.move(deltaX, deltaY);
}
