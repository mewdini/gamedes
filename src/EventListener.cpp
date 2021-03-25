#include "EventListener.h"

EventListener::EventListener(){

};

void EventListener::checkEvent(sf::Event Event,sf::RenderWindow App){
    if(Event.type == sf::Event::Closed)
        App.close();
      if(Event.type == sf::Event::KeyPressed){
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
          //move paddle up
          if(state==1){
            leftpaddle.moveUp();
            break;
          }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
          //move paddle down
          if(state==1){
            leftpaddle.moveDown();
            break;
          }
        }
}