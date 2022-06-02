#ifndef PLAYER_H
#define PLAYER_H

#include "../Headers.h"

class Player
{
  private:
    sf::RectangleShape shape;
    float speed {0.f};
    sf::Vector2f velocity;
    float gravityFactor {0.f};

    // Initialisers
    void initShape();

  public:
    // Constructor
    Player();

    // Modifiers
    void setTexture(sf::Texture* texture);
    void setSpeed(const float speed);
    void setVelocity(const sf::Vector2f velocity);
    void setVelocityX(const float velocity);
    void setVelocityY(const float velocity);
    void setGravityFactor(const float gravityFactor);

    // Accessors
    const sf::FloatRect getBounds() const;
    const sf::Vector2f getVelocity() const;

    // Functions
    void update();
    void render(sf::RenderTarget& target);
};

#endif // PLAYER_H
