// Updated by Zack on 4/10
#include "BlockActor.h"

BlockActor::BlockActor(){
    sprite.setPosition(0,0);
}

BlockActor::BlockActor(float posX, float posY, int left, int top, int width, int height){
    sprite.setPosition(posX, posY);
    sf::IntRect rect(left, top, width, height);
    sprite.setTextureRect(rect);
}

float BlockActor::getLocationX(){
    return sprite.getPosition().x;
}

float BlockActor::getLocationY(){
    return sprite.getPosition().y;
}

void BlockActor::setViewLocation(int newLeft, int newTop){
    sprite.getTextureRect().left = newLeft;
    sprite.getTextureRect().top = newTop;
}

void BlockActor::setViewDimensions(int newWidth, int newHeight){
    sprite.getTextureRect().width = newWidth;
    sprite.getTextureRect().height = newHeight;
}

void BlockActor::move(float deltaX, float deltaY){
    sprite.move(deltaX, deltaY);
}

void BlockActor::setTexture(sf::Texture texture){
    sprite.setTexture(texture);
}
