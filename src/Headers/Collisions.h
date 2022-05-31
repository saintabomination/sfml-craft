#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "../Headers.h"

class Collisions
{
  public:
    static bool pointVsRect(sf::Vector2f point, sf::FloatRect rect);
    static bool rectVsRect(sf::FloatRect rectOne, sf::FloatRect rectTwo);
};

#endif // COLLISIONS_H
