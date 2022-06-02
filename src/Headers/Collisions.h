#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "../Headers.h"

class Collisions
{
  public:
    static bool pointVsRect(sf::Vector2f point, sf::FloatRect rect);
    static bool rectVsRect(sf::FloatRect rectOne, sf::FloatRect rectTwo);
    static bool rayVsRect(sf::Vector2f rayOrigin, sf::Vector2f rayDir, sf::FloatRect rect, sf::Vector2f contactPoint, sf::Vector2f contactNormal, float& t_hit_near);
    static bool dynamicRayVsRect(sf::FloatRect rectOne, sf::FloatRect rectTwo, sf::Vector2f velocity, sf::Vector2f contactPoint, sf::Vector2f contactNormal, float& fTime);
};

#endif // COLLISIONS_H
