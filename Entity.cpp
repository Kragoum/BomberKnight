#include "Entity.h"

Entity::Entity()
{
    // Shape
    this->shape.setPosition(400.f,300.f);
    this->shape.setSize(sf::Vector2f(100.f, 100.f));
    this->shape.setScale(sf::Vector2f(0.5f,0.5f));
    this->shape.setFillColor(sf::Color::Red);
    this->shape.setOutlineColor(sf::Color::Black);
    this->shape.setOutlineThickness(5.f);
    // MS
    this->moveSpeed = 100.f;
}


Entity::~Entity()
{
}

void Entity::move(const float& dt,const float dir_x, const float dir_y)
{
    this->shape.move(dir_x*this->moveSpeed*dt, dir_y*this->moveSpeed*dt);
}


void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget& target)
{
    target.draw(this->shape);
}
