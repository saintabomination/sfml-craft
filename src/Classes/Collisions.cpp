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

bool Collisions::rectVsRect(sf::FloatRect rectOne, sf::FloatRect rectTwo)
{
  return (
    rectOne.left < rectTwo.left + rectTwo.width &&
    rectOne.left + rectOne.width > rectTwo.left &&
    rectOne.top < rectTwo.top + rectTwo.height &&
    rectOne.top + rectOne.height > rectTwo.top
  );
}
