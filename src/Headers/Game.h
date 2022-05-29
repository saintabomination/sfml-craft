#ifndef GAME_H
#define GAME_H

#include "../Headers.h"
#include "TextureManager.h"
#include "Player.h"
#include "Block.h"

class Game
{
  private:
    sf::RenderWindow* window;
    sf::Event sfEvent;

    // Members
    TextureManager textureManager;
    Player player;
    std::vector<Block> blocks;

    // Initialisers
    void initWindow();
    void initTextures();
    void initPlayer();
    void initBlocks();

  public:
    // Constructor and Destructor
    Game();
    virtual ~Game();

    // Update Functions
    void updateSFMLEvents();
    void updateKeys();
    void update();

    // Render Functions
    void renderBlocks();
    void render();

    // Functions
    void run();
};

#endif // GAME_H
