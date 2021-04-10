// Updated by Zack on 4/10
#include "BlockActor.h"

BlockActor::BlockActor(){
    block.setSize(0,0);
    block.setPosition(0,0);
}

BlockActor::BlockActor(int posX, int posY, int width, int height){
    block.setSize(width, height);
    block.setPosition(posX, posY);
}

int BlockActor::getLocationX(){
    return block.getPosition().x;
}

int BlockActor::getLocationY(){
    return block.getPosition().y;
}

void BlockActor::move(float deltaX, float deltaY){
    block.move(deltaX, deltaY);
}
