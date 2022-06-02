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

bool Collisions::rayVsRect(sf::Vector2f rayOrigin, sf::Vector2f rayDir, sf::FloatRect rect, sf::Vector2f contactPoint, sf::Vector2f contactNormal, float& t_hit_near)
{
  sf::Vector2f pos = sf::Vector2f(rect.left, rect.top);
  sf::Vector2f size = sf::Vector2f(rect.width, rect.height);
  sf::Vector2f t_near = pos - rayOrigin;
  t_near.x /= rayDir.x;
  t_near.y /= rayDir.y;
  sf::Vector2f t_far = pos + size - rayOrigin;
  t_far.x /= rayDir.x;
  t_far.y /= rayDir.y;

  if (t_near.x > t_far.x) std::swap(t_near.x, t_far.x);
  if (t_near.y > t_far.y) std::swap(t_near.y, t_far.y);

  if (t_near.x > t_far.y || t_near.y > t_far.x) return false;

  t_hit_near = std::max(t_near.x, t_near.y);
  float t_hit_far = std::min(t_far.x, t_far.y);

  if (t_hit_far < 0.f) return false;

  contactPoint = sf::Vector2f(rayOrigin.x + t_hit_near * rayDir.x, rayOrigin.y + t_hit_near * rayDir.y);

  if (t_near.x > t_near.y)
    if (rayDir.x < 0)
      contactNormal = { 1, 0 };
    else
      contactNormal = { -1, 0};
  else if (t_near.x < t_near.y)
    if (rayDir.y < 0)
      contactNormal = { 0, 1 };
    else
      contactNormal = { 0, -1 };

  return true;
}
