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
    sf::View view;

    // Members
    TextureManager textureManager;
    Player player;
    std::vector<Block> blocks;

    // Clocks
    sf::Clock dtClock;
    float dtTimer;

    // Initialisers
    void initWindow();
    void initTextures();
    void initPlayer();
    void initBlocks();

  public:
    // Constructor and Destructor
    Game();
    virtual ~Game();

    // Accessors
    const float getDt() const;

    // Update Functions
    void updateSFMLEvents();
    void updateClocks();
    void updateKeys();
    void updatePlayer();
    void updateView();
    void update();

    // Render Functions
    void renderBlocks();
    void render();

    // Functions
    void run();
};

#endif // GAME_H
