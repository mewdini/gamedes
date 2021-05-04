//
// Created by Miodrag
#define _USE_MATH_DEFINES
#include "Tower.h"
#include <cmath>
#include <memory>

using namespace sf;
Tower::Tower(int x, int y, int level)
{
    // these are sf::
    tower_sprite = Sprite();
    tower_tex = Texture();

    TowerLevel(level);
    tower_sprite.setPosition(x, y);

}

Tower::Tower()
{
    radius = 128.0f;
}

void Tower::TowerLevel(int lvl)
{
    level = lvl;
    radius = 128;
    gold_cost = 100 * lvl;
    tower_sprite.setTexture(tower_tex);

    switch(lvl)
    {
        case 1:
            attack_speed = 1.0f;
            damage = 15;
            break;

        case 2:
            attack_speed = 2.0f;
            damage = 30;
            break;

        case 3:
            attack_speed = 3.0f;
            damage = 40;
            break;

        case 4:
            attack_speed = 4.0f;
            damage = 50;
            break;

        case 5:
            attack_speed = 4.0f;
            damage = 60;
    }

}

double Tower::angle_to_point(double x, double y)
{
    double dx = x - (tower_sprite.getPosition().x);
    double dy = y - (tower_sprite.getPosition().y);
    double angle =  atan2(dx,dy) * 180 / M_PI;
    return angle;
}

void Tower::Update(float elapsedTime)
{
    ;   //still have to figure out how we going to update

}

const float Tower::GetRadius()
{
    return radius;
}

const float Tower::GetAttackSpeed()
{
    return attack_speed;
}

const float Tower::GetDamage()
{
    return damage;
}

const Vector2f Tower::GetPosition()
{
    return tower_sprite.getPosition();
}

const FloatRect Tower::GetBoundingBox()
{
    return tower_sprite.getGlobalBounds();
}

const Vector2f Tower::GetCenteredPosition()
{
    Vector2f vec = tower_sprite.getPosition();
    vec.x += GetBoundingBox().width / 2;
    vec.y += GetBoundingBox().height / 2;
    return vec;
}

const int Tower::GetGoldCost(int level)
{
    return gold_cost;
}

const int Tower::GetUpgradeLevel()
{
    return upgrade_level;
}

void Tower::Attack(Virus* virus)
{
    // TODO animate attack

    // Creates a bullet on top of tower and sets its target to the given virus
    bullet = Bullet(sprite.getPosition().x + 15, sprite.getPosition().y + 15, 0, 550, 20, 20, virus, &damage);


    //virus->hit(damage);
}
