//
// Created by Miodrag
//
#pragma once
#ifndef GAMEDES_VIRUSES_H
#define GAMEDES_VIRUSES_H

#include <SFML/Graphics.hpp>
#include "SpriteActor.h"
#include "Directions.h"
#include "Stage.h"

using namespace sf;

class Virus: public SpriteActor{

public:
    enum Viruses {covid, resistant, contagious, airborn, coughing};

    Virus(int, int, Directions, Virus::Viruses, int, Stage*);
    
    //When virus is hit
    bool hit(float);

    //Find out if virus is alive
    bool isAlive();

    void setAlive(bool);

    void movement();
    //Spawn a new virus
    void spawn(float startX, float startY, Virus::Viruses type, int seed);

    //Return position
    Vector2f getPosition();

    //Get a copy of the sprite to draw
    Sprite getSprite();

    //Update Virus Each Frame, baseLocation is the location of the
    //base that is on the end of the road, we are updating the virus
    //while its chasing towards the base on the end of the road
    void update(Int64);

    void updateDirection();

    void moveDir(Directions, Int64);

    // Directions pathDir();

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

    //Sprite for Virus
    Sprite m_Sprite;

    Texture m_Texture;

    //How fast can virus move
    float m_Speed;

    //How much health does the virus have
    float m_Health;

    //Is it still alive?
    bool m_Alive;

    Stage* m_Stage;

    Directions m_Dir;

    //Did the virus already turn in this box?
    bool m_Turned;
};




#endif //GAMEDES_VIRUSES_H
