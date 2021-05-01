//
// Created by Miodrag
//
#pragma once
#ifndef GAMEDES_VIRUSES_H
#define GAMEDES_VIRUSES_H

#include <SFML/Graphics.hpp>
#include "SpriteActor.h"
using namespace sf;
class Virus: public SpriteActor{

public:
    Virus();
    
    //When virus is hit 
    bool hit(float);

    //Find out if virus is alive
    bool isAlive();

    void movement();
    //Spawn a new virus
    void spawn(float startX, float startY, int type, int seed);

    //Return position
    Vector2f getPosition();

    //Get a copy of the sprite to draw
    Sprite getSprite();

    //Update Virus Each Frame, baseLocation is the location of the
    //base that is on the end of the road, we are updating the virus
    //while its chasing towards the base on the end of the road
    void update(float elapsedTime, Vector2f baseLocation);

private:
    //Virus speeds
    float COVID_VIRUS_SPEED = 45;
    float RESISTANT_STRAIN_SPEED= 60;
    float CONTAGIOUS_STRAIN_SPEED = 70;
    float AIRBORN_STRAIN_SPEED = 80;
    float COUGHING_PERSON_SPEED = 100;

    //Virus Health
    float COVID_VIRUS_HEALTH = 100;
    float RESISTANT_STRAIN_HEALTH = 200;
    float CONTAGIOUS_STRAIN_HEALTH = 250;
    float AIRBORN_STRAIN_HEALTH = 300;
    float COUGHING_PERSON_HEALTH = 400;

    // SPEED of the VIRUS
    int MAX_VARIANCE = 30;
    int OFFSET = 101 - MAX_VARIANCE;

    //Position of the Virus
    Vector2f m_Position;

    // Zack - removed sprite and texture

    //How fast can virus move
    float m_Speed;

    //How much health does the virus have
    float m_Health;

    //Is it still alive?
    bool m_Alive;

};




#endif //GAMEDES_VIRUSES_H
