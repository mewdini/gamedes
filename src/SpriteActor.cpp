// Updated by Zack on 4/10
#include "SpriteActor.h"

SpriteActor::SpriteActor(){
    sprite.setPosition(0,0);
}

SpriteActor::SpriteActor(float posX, float posY, int left, int top, int width, int height){
    sprite.setPosition(posX, posY);
    sf::IntRect rect(left, top, width, height);
    sprite.setTextureRect(rect);
}

float SpriteActor::getLocationX(){
    return sprite.getPosition().x;
}

float SpriteActor::getLocationY(){
    return sprite.getPosition().y;
}

void SpriteActor::setViewLocation(int newLeft, int newTop){
    sprite.getTextureRect().left = newLeft;
    sprite.getTextureRect().top = newTop;
}

void SpriteActor::setViewDimensions(int newWidth, int newHeight){
    sprite.getTextureRect().width = newWidth;
    sprite.getTextureRect().height = newHeight;
}

void SpriteActor::move(float deltaX, float deltaY){
    sprite.move(deltaX, deltaY);
}

void SpriteActor::setTexture(sf::Texture texture){
    sprite.setTexture(texture);
}

sf::Sprite SpriteActor::getSprite(){
    return sprite;
}
