#include "../Headers/Block.h"

// Initialisers

void Block::initShape()
{
  this->shape.setSize(sf::Vector2f(32.f, 32.f));
}

// Accessors

const sf::FloatRect Block::getBounds() const
{
  return this->shape.getGlobalBounds();
}

// Constructor

Block::Block(sf::Vector2f position, sf::Texture* texture)
{
  this->initShape();
  this->shape.setPosition(position);
  this->shape.setTexture(texture);
}

// Functions

void Block::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
