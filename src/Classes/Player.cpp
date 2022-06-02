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
  this->velocity.y = 1.f;
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

void Player::setVelocity(const sf::Vector2f velocity)
{
  this->velocity = velocity;
}

void Player::setVelocityX(const float velocity)
{
  this->velocity.x = velocity;
}

void Player::setVelocityY(const float velocity)
{
  this->velocity.y = velocity;
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

const sf::Vector2f Player::getVelocity() const
{
  return sf::Vector2f(
    this->velocity.x * this->speed * game.getDt(),
    this->velocity.y * this->gravityFactor * game.getDt()
  );
}

// Functions

void Player::update()
{
  this->shape.move(sf::Vector2f(
    this->velocity.x * this->speed * game.getDt(),
    this->velocity.y * this->gravityFactor * game.getDt()
  ));
}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
