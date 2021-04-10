//
// Created by Miodrag


#include "Virus.h"
#include <cstdlib>
#include <ctime>
using namespace  std;


void Virus::setStage(Stage* s)
{
    Virus::stage = s;
}

void Virus::spawn(float startX, float startY, int type, int seed)
{
    switch(type)
    {
        case 0:
            //Covid Virus
            //this m_Sprite variable will pull the sprite of the Zombie
            //We should probably create a TextureHolder Class from where we
            // load it
            // m_Sprite = Sprite(TextureHolder)
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

bool Virus::hit()
{
    m_Health--;
    if (m_Health < 0)
    {
        //DEAD
        m_Alive = false;
        //m_Sprite.setTexture(TextureHolder::GetTexture("graphicsHere")
        //this sprite creates a dead Virus on the map if we want that
        // we can just make it disapear
        return true;


    }

    //injured and not dead yet
    return false;

}

void Virus::movement()
{
    &Virus::stage.getValueOnMap();
    move(1,1);

}



bool Virus::isAlive()
{
    return m_Alive;
}

//FloatRect Virus::getPosition()
//{
    // return m_Sprite.getGlobalBounds();
//}


//Sprite Virus::getSprite()
//{
  //  return m_Sprite;
//}




// This function has to update virus location from the base
//void Virus::update(float elapsedTime, Vector2f baseLocation)
//{
//    float baseX = baseLocation.x;
//    float baseY = baseLocation.y;
//    //Update Virus position
//
//
//}
