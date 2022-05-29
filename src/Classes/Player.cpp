#include "../Headers/Player.h"

// Initialisers

void Player::initShape()
{
  this->shape.setSize(sf::Vector2f(32.f, 32.f));
}

// Constructor

Player::Player()
{
  this->initShape();
}

// Modifiers

void Player::setTexture(sf::Texture* texture)
{
  this->shape.setTexture(texture);
}

void Player::setSpeed(const float speed)
{
  this->speed = speed;
}

// Functions

void Player::update()
{

}

void Player::move(sf::Vector2f movement)
{
  this->shape.move(movement * this->speed);
}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
