#include "../Headers/Player.h"
#include "../Headers/Game.h"

extern Game game;

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

void Player::setGravityFactor(const float gravityFactor)
{
  this->gravityFactor = gravityFactor;
}

// Accessors

const sf::FloatRect Player::getBounds() const
{
  return this->shape.getGlobalBounds();
}

// Functions

void Player::update()
{
  // this->shape.move(sf::Vector2f(0.f, this->gravityFactor * game.getDt()));
}

void Player::move(sf::Vector2f movement)
{
  this->shape.move(movement * this->speed * game.getDt());
}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
