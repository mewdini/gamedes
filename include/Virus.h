//
// Created by Miodrag
//
#pragma once
#ifndef GAMEDES_VIRUSES_H
#define GAMEDES_VIRUSES_H

#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "SpriteActor.h"
#include "Directions.h"

using namespace sf;

enum Viruses {covid, resistant, contagious, airborn, coughing};
class Virus: public SpriteActor{

public:

    Virus(int, int, Directions, Viruses, int, int*);
    
    //When virus is hit 
    bool hit(float);

    //Find out if virus is alive
    bool isAlive();

    void setAlive(bool);

    void movement();
    //Spawn a new virus
    void spawn(float startX, float startY, Viruses type, int seed);

    //Return position
    Vector2f getPosition();

    //Get a copy of the sprite to draw
    Sprite getSprite();

    //Update Virus Each Frame, baseLocation is the location of the
    //base that is on the end of the road, we are updating the virus
    //while its chasing towards the base on the end of the road
    int update(Int64, Vector2i*, float*);

    void updateDirection();

    void moveDir(Directions, Int64);

    // Directions pathDir();

    Vector2i pixelToGrid(Vector2f);

    // gets pixel coords of middle of grid square
    Vector2f gridToPixelMiddle(Vector2i);

    Vector2f gridToPixelTopLeft(Vector2i);

    int getValueOnMap(int x,int y);

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

    //Virus Damage
    float COVID_VIRUS_DAMAGE = 20; //maybe end game if 5 reaches the base
    float RESISTANT_STRAIN_DAMAGE = 200;
    float CONTAGIOUS_STRAIN_DAMAGE = 300;
    float AIRBORN_STRAIN_DAMAGE = 400;
    float COUGHING_STRAIN_DAMAGE = 500;

    // SPEED of the VIRUS
    int MAX_VARIANCE = 30;
    int OFFSET = 101 - MAX_VARIANCE;

    // Zack - removed sprite and texture

    //How fast can virus move
    float m_Speed;

    //How much health does the virus have
    float m_Health;

    //How much damage does the virus deal
    float m_Damage;

    //Is it still alive?
    bool m_Alive = false;

    int m_Grid[192] = {0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,7,6,6,6,6,6,6,8,0,0,0,0,0,0,0,0,5,3,0,0,0,0,3,5,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,5,0,0,0,0,0,0,5,0,0,0,0,0,
    0,0,0,5,3,0,0,0,0,3,5,0,0,0,0,0,0,0,0,5,0,0,0,1,0,0,5,0,0,0,7,6,0,0,0,5,0,0,0,5,0,0,5,0,0,0,5,3,0,0,0,5,0,0,0,5,0,3,5,3,0,3,5,0,0,0,0,5,3,0,3,5,0,0,9,6,6,6,10,0,0,0,0,9,6,6,6,10,0,0,0,0,3,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    Directions m_Dir;

    //Did the virus already turn in this box?
    bool m_Turned;

    int gainGold=0;
};




#endif //GAMEDES_VIRUSES_H
