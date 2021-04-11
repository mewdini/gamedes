//
// Created by Miodrag
//
#pragma once
#ifndef GAMEDES_VIRUSES_H
#define GAMEDES_VIRUSES_H

#include <SFML/Graphics.hpp>
#include "Stage.h"
using namespace sf;
class Virus
{
private:
    //Virus speeds
    const float COVID_VIRUS_SPEED = 45;
    const float RESISTANT_STRAIN_SPEED= 60;
    const float CONTAGIOUS_STRAIN_SPEED = 70;
    const float AIRBORN_STRAIN_SPEED = 80;
    const float COUGHING_PERSON_SPEED = 100;

    //Virus Health
    const float COVID_VIRUS_HEALTH = 100;
    const float RESISTANT_STRAIN_HEALTH = 200;
    const float CONTAGIOUS_STRAIN_HEALTH = 250;
    const float AIRBORN_STRAIN_HEALTH = 300;
    const float COUGHING_PERSON_HEALTH = 400;

    // SPEED of the VIRUS
    const int MAX_VARIANCE = 30;
    const int OFFSET = 101 - MAX_VARIANCE;

    //Position of the Virus
    Vector2f m_Position;

    //Sprite for Virus
    Sprite m_Sprite;

    Texture m_Texture;

    //How fast can virus move
    float m_Speed;

    //How much health does it got
    float m_Health;

    //Is it still alive?
    bool m_Alive;

public:
    //When virus is hit
    bool hit();

    //Find out if virus is alive
    bool isAlive();

    void movement();
    //Spawn a new virus
    void spawn(float startX, float startY, int type, int seed);

    //Return a rectangle that is position in the world
    FloatRect getPosition();

    //Get a copy of the sprite to draw
    Sprite getSprite();

    //Update Virus Each Frame, baseLocation is the location of the
    //base that is on the end of the road, we are updating the virus
    //while its chasing towards the base on the end of the road
    void update(float elapsedTime, Vector2f baseLocation);

};




#endif //GAMEDES_VIRUSES_H
