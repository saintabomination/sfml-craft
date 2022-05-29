#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"

class Player
{
  private:
    sf::RectangleShape shape;

    // Initialisers
    void initShape();

  public:
    // Constructor
    Player();

    // Modifiers
    void setTexture(sf::Texture* texture);

    // Functions
    void update();
    void render(sf::RenderTarget& target);
};

#endif // PLAYER_H
