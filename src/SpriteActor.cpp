// Updated by Zack on 4/10
#include "SpriteActor.h"

SpriteActor::SpriteActor(){
    sprite.setPosition(0,0);
}

SpriteActor::SpriteActor(float posX, float posY, int left, int top, int width, int height){
    sprite.setPosition(posX, posY);
    textureRect = sf::IntRect(left, top, width, height);
    sprite.setTextureRect(textureRect);
}

float SpriteActor::getLocationX(){
    return sprite.getPosition().x;
}

float SpriteActor::getLocationY(){
    return sprite.getPosition().y;
}

void SpriteActor::setViewLocation(int newLeft, int newTop){
    textureRect.left = newLeft;
    textureRect.top = newTop;
    sprite.setTextureRect(textureRect);
}

void SpriteActor::setViewDimensions(int newWidth, int newHeight){
    textureRect.width = newWidth;
    textureRect.height = newHeight;
    sprite.setTextureRect(textureRect);
}

void SpriteActor::move(float deltaX, float deltaY){
    sprite.move(deltaX, deltaY); // amount of pixels to move in X and Y directions
    // or sprite.setLocation(X, Y);
}

void SpriteActor::setTexture(sf::Texture* text){
    sprite.setTexture(*text);
}

sf::Sprite SpriteActor::getSprite(){
    return sprite;
}
