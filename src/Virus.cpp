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
    // Zack - changed to use existing sprite from inherited SpriteActor
    // doesn't solve problem of loading a new texture, should have reference to
    // PView's texture and load from that instead
    sf::Texture m_Texture;
    m_Texture.loadFromFile("../data/coronavirus_0.png");
    switch(type)
    {
        case 0:
            //Covid Virus
            //this sprite variable will pull the sprite of the Zombie
            //We should probably create a TextureHolder Class from where we
            // load it
            this->setTexture(&m_Texture);
            //sprite.setOrigin(15, 6); 
            m_Speed = COVID_VIRUS_SPEED;
            m_Health = COVID_VIRUS_HEALTH;
            break;

        case 1:
            // Resistant Strain
            // sprite = Sprite(TextureHolder)
            m_Speed = RESISTANT_STRAIN_SPEED;
            m_Health = RESISTANT_STRAIN_HEALTH;
            break;

        case 2:
            // Contagious Strain
            // sprite = Sprite(TextureHolder)
            m_Speed = CONTAGIOUS_STRAIN_SPEED;
            m_Health = CONTAGIOUS_STRAIN_HEALTH;
            break;

        case 3:
            // Airborn Strain
            // sprite = Sprite(TextureHolder)
            m_Speed = AIRBORN_STRAIN_SPEED;
            m_Health = AIRBORN_STRAIN_HEALTH;
            break;

        case 4:
            // Coughing Strain
            // sprite = Sprite(TextureHolder)
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
    //sprite.setOrigin(location);
    //sprite.setPosition(m_Position);

}

bool Virus::hit(float damage)
{
    m_Health -= damage;
    if (m_Health <= 0)
    {
        //DEAD
        m_Alive = false;
        //sprite.setTexture(TextureHolder::GetTexture("graphicsHere")
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
    return sprite.getPosition();
}


Sprite Virus::getSprite()
{
   return sprite;
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