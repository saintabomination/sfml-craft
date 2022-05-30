#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"

class Player
{
  private:
    sf::RectangleShape shape;
    float speed {0.f};
    float gravityFactor {0.f};

    // Initialisers
    void initShape();

  public:
    // Constructor
    Player();

    // Modifiers
    void setTexture(sf::Texture* texture);
    void setSpeed(const float speed);
    void setGravityFactor(const float gravityFactor);

    // Accessors
    const sf::FloatRect getBounds() const;

    // Functions
    void update();
    void move(sf::Vector2f movement);
    void render(sf::RenderTarget& target);
};

#endif // PLAYER_H
