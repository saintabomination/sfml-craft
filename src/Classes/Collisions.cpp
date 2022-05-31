#include "../Headers/Collisions.h"

bool Collisions::pointVsRect(sf::Vector2f point, sf::FloatRect rect)
{
  return (
    point.x >= rect.left &&
    point.y >= rect.top &&
    point.x < rect.left + rect.width &&
    point.y < rect.top + rect.height
  );
}
