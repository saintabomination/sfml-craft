#ifndef GAME_H
#define GAME_H

#include "../Headers.h"
#include "TextureManager.h"
#include "Player.h"

class Game
{
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;

    // Members
    TextureManager textureManager;
    Player player;

    // Initialisers
    void initWindow();
    void initTextures();
    void initPlayer();

  public:
    // Constructor and Destructor
    Game();
    virtual ~Game();

    // Update Functions
    void updateSFMLEvents();
    void update();

    // Render Functions
    void render();

    // Functions
    void run();
};

#endif // GAME_H
