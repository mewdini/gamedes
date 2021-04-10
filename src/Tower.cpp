//
// Created by Miodrag
#include "Tower.h"
#include <cmath>

using namespace sf;
Tower::Tower(int x, int y, int level)
{
    // these are sf::
    this->tower_sprite = Sprite();
    this->tower_tex = Texture();

    TowerLevel(lvl);
    this->tower_sprite.setPosition(x, y);
}

Tower::Tower()
{
    this->radius = 128.0f;
}

void Tower::TowerLevel(int lvl);
{
    this->level = lvl;
    this->radius = 128;
    this->gold_cost = 100 * lvl;
    this->tower_sprite.setTexture(*tower_tex);

    switch(lvl)
    {
        case 1:
            this->attack_speed = 1.0f;
            this->damage = 15;
            break;

        case 2:
            this->attack_speed = 2.0f;
            this->damage = 30;
            break;

        case 3:
            this->attack_speed = 3.0f;
            this->damage = 40;
            break;

        case 4:
            this->attack_speed = 4.0f;
            this->damage = 50;
            break;

        case 5:
            this->attack_speed = 4.0f;
            this->damage = 60;
    }

}

void Tower::angle_to_point(double x, double y)
{
    double dx = x - (tower_sprite.getPosition().x);
    double dy = y - (tower_srpite.getPosition().y);
    double angle = atan2(dx,dy) * 180 / (atan(1) * 4);
    return angle;
}

void Tower::Update(float elapsedTime)
{
    ;   //still have to figure out how we going to update

}

const int Tower::GetX()
{
    return (int)tower_sprite.getPosition().x;
}

const int Tower::GetY()
{
    return (int)tower_sprite.getPosition().y;
}

const float Tower::GetRadius()
{
    return this->radius;
}

const float Tower::GetAttackSpeed()
{
    return this->attack_speed;
}

const float Tower::GetDamage()
{
    return this->damage;
}

const Vector2f Tower::GetPosition()
{
    return this->tower_sprite.getPosition();
}

const FloatRect Tower::GetBoundingBox()
{
    return this->tower_sprite.getGlobalBounds;
}

const Vector2f Tower::GetCenteredPosition()
{
    Vector2f vec = this->tower_sprite.getPosition();
    vec.x += GetBoundingBox().width / 2;
    vec.y += GetBoundingBox().height / 2;
    return vec;
}

const int Tower::GetGoldCost()
{
    return this->gold_cost;
}

const int Tower::GetUpgradeLevel()
{
    return this->upgrade_level;
}
