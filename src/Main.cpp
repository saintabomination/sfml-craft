#include "Headers.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML");
  sf::CircleShape shape(128.f);
  shape.setFillColor(sf::Color::Red);

  while (window.isOpen())
  {
    sf::Event sfEvent;
    while (window.pollEvent(sfEvent))
    {
      switch (sfEvent.type)
      {
        case sf::Event::Closed:
          window.close();
          break;

        default:
          break;
      }
    }

    window.clear();
    window.draw(shape);
    window.display();
  }

  return 0;
}
