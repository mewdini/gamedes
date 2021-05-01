//
// Created by M on 4/29/21.
//

#include "Entity.h"


Entity::Entity()
{
    this->shape.setSize(sf::Vector2f(50.f, 50.f));
    this->shape.setFillColor(sf::Color::White);
    this->movementSpeed = 100.f;
}


Entity::~Entity()
{
    ;
}

void Entity::move(const float& dt, const float dir_x, const float dir_y)
{
    auto temp = shape.getPosition(); // this makes down movement not crash -- even not assigning doesn't fix it
    this->shape.move(dir_x * this->movementSpeed * dt/1000000, dir_y * this->movementSpeed * dt/1000000);
}

void Entity::update(const float &dt)
{
    ;
}

void Entity::render(sf::RenderTarget* target)
{
    target->draw(this->shape);
}