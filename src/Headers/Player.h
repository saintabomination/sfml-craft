#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"

class Player
{
  private:
    sf::RectangleShape shape;
    float speed = 0.f;

    // Initialisers
    void initShape();

  public:
    // Constructor
    Player();

    // Modifiers
    void setTexture(sf::Texture* texture);
    void setSpeed(const float speed);

    // Functions
    void update();
    void move(sf::Vector2f movement);
    void render(sf::RenderTarget& target);
};

#endif // PLAYER_H
