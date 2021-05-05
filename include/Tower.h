//
// Created by Miodrag
//

#pragma once
#include <SFML/Graphics.hpp>
#include "Virus.h"
#include "Bullet.h"

using namespace std;
using namespace sf;

enum Towers{first};
class Tower : public SpriteActor
{
public:
    Tower();
    //void Draw(RenderTarget *Whatever)
    explicit Tower(int x, int y, Towers level);
    //draw function needs a target to draw
    //void Draw(RenderTarget *something);
    void Update(float elapsedTime);
    const float GetRadius();
    const float GetAttackSpeed();
    const float GetDamage();
    const Vector2f GetPosition();
    const Vector2f GetCenteredPosition();
    const FloatRect GetBoundingBox();
    const int GetUpgradeLevel();
    const float GetGoldCost(Towers level);
    void TowerLevel(Towers lvl);
    void Attack(Virus*, Texture*);
    Bullet getBullet();
    bool GetReadyToAttack();
    void SetReadyToAttack(bool);

private:
    Texture tower_tex;
    Sprite tower_sprite;
    int level;
    float radius;
    float attack_speed;
    float damage;
    double angle_to_point(double x, double y);
    int upgrade_level;
    Bullet bullet;
    // Pixel Position since the sprite isn't storing it
    int pixX;
    int pixY;
    bool ready_to_attack;
protected:
    float gold_cost;

};
