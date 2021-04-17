//
// Created by Miodrag


#include "Virus.h"
#include <cstdlib>
#include <ctime>
using namespace  std;


Virus::Virus()
{
    ;
}

// void Virus::setStage(Stage* s)
// {
//    stage = s;
// }

// TODO make virus enum
void Virus::spawn(float startX, float startY, int type, int seed)
{
    switch(type)
    {
        case 0:
            //Covid Virus
            //this m_Sprite variable will pull the sprite of the Zombie
            //We should probably create a TextureHolder Class from where we
            // load it
            m_Texture.loadFromFile("../data/coronaviurs_0.png");
            m_Sprite.setTexture(m_Texture);
            m_Sprite.setOrigin(15, 6);
            m_Speed = COVID_VIRUS_SPEED;
            m_Health = COVID_VIRUS_HEALTH;
            break;

        case 1:
            // Resistant Strain
            // m_Sprite = Sprite(TextureHolder)
            m_Speed = RESISTANT_STRAIN_SPEED;
            m_Health = RESISTANT_STRAIN_HEALTH;
            break;

        case 2:
            // Contagious Strain
            // m_Sprite = Sprite(TextureHolder)
            m_Speed = CONTAGIOUS_STRAIN_SPEED;
            m_Health = CONTAGIOUS_STRAIN_HEALTH;
            break;

        case 3:
            // Airborn Strain
            // m_Sprite = Sprite(TextureHolder)
            m_Speed = AIRBORN_STRAIN_SPEED;
            m_Health = AIRBORN_STRAIN_HEALTH;
            break;

        case 4:
            // Coughing Strain
            // m_Sprite = Sprite(TextureHolder)
            m_Speed = COUGHING_PERSON_SPEED;
            m_Health = COUGHING_PERSON_HEALTH;
            break;



    }

    m_Alive = true;

    //Every virus has a unique speed
    srand((int)time(0) * seed);
    float modifier = (rand() % MAX_VARIANCE) + OFFSET;
    modifier /= 100;  //it will equal between .7 and 1
    m_Speed *= modifier;

    // Location of the virus
    m_Position.x = startX;
    m_Position.y = startY;
    //Setting origin
    //m_Sprite.setOrigin(location);
    //m_Sprite.setPosition(m_Position);

}

bool Virus::hit(float damage)
{
    m_Health -= damage;
    if (m_Health <= 0)
    {
        //DEAD
        m_Alive = false;
        //m_Sprite.setTexture(TextureHolder::GetTexture("graphicsHere")
        //this sprite creates a dead Virus on the map if we want that
        // we can just make it disappear
        return true;


    }

    //injured and not dead yet
    return false;

}

// void Virus::movement()
// {
//     stage.getValueOnMap();
//     move(1,1);

// }



bool Virus::isAlive()
{
    return m_Alive;
}

Vector2f Virus::getPosition()
{
    return m_Sprite.getPosition();
}


Sprite Virus::getSprite()
{
   return m_Sprite;
}




// This function has to update virus location from the base
//void Virus::update(float elapsedTime, Vector2f baseLocation)
//{
//    float baseX = baseLocation.x;
//    float baseY = baseLocation.y;
//    //Update Virus position
//
//
//}