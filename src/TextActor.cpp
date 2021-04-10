// Updated by Zack on 4/10
#include "TextActor.h"
#include <string>

TextActor:: TextActor(sf::Font font, int x, int y, std::string content){
    text.setFont(font);
    text.setPosition(x, y);
    text.setString(content);
}

int TextActor::getLocationX(){
    return text.getPosition().x;
}

int TextActor::getLocationY(){
    return text.getPosition().y;
}

void TextActor::move(float deltaX, float deltaY){
    text.move(deltaX, deltaY);
}

void TextActor::setContent(std::string content){
    text.setString(content);
}
