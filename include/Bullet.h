
#ifndef Bullet_h
#define Bullet_h
#include <SFML/Graphics.hpp>
#include "SpriteActor.h"
#include "Virus.h"

class Bullet : SpriteActor{

    public:
        Bullet(float, float, int, int, int, int, Virus) : SpriteActor(float, float, int, int, int, int);
        void follow();
        bool detectHit();

    private:
        Virus target;

}

#endif