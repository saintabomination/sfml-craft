#ifndef BLOCK_H
#define BLOCK_H

#include "../Headers.h"

class Block
{
  private:
    sf::RectangleShape shape;

    // Initialisers
    void initShape();

  public:
    // Constructor
    Block(sf::Vector2f position, sf::Texture* texture);

    // Functions
    void render(sf::RenderTarget& target);
};

#endif // BLOCK_H
