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

// Functions

void Player::update()
{

}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
