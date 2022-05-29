#include "../Headers/Game.h"

// Initialisers

void Game::initWindow()
{
  this->window = new sf::RenderWindow(sf::VideoMode(640, 480), "SFML");
  this->window->setFramerateLimit(60);
  this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
  this->textureManager.addTexture("player", "src/Assets/Textures/stew.png");
  this->textureManager.addTexture("grass", "src/Assets/Textures/grass.png");
}

void Game::initPlayer()
{
  this->player.setTexture(this->textureManager.getTexture("player"));
}

void Game::initBlocks()
{
  for (int x = 0; x < 20; x++)
  {
    this->blocks.push_back(Block(sf::Vector2f(x * 32.f, 448.f), this->textureManager.getTexture("grass")));
  }
}

// Constructor and Destructor

Game::Game()
{
  this->initWindow();
  this->initTextures();
  this->initPlayer();
  this->initBlocks();
}

Game::~Game()
{
  delete this->window;
}

// Update Functions

void Game::updateSFMLEvents()
{
  while (this->window->pollEvent(this->sfEvent))
  {
    switch (this->sfEvent.type)
    {
      case sf::Event::Closed:
        this->window->close();
        break;

      default:
        break;
    }
  }
}

void Game::update()
{
  this->updateSFMLEvents();
  this->player.update();
}

// Render Functions

void Game::renderBlocks()
{
  for (Block block : this->blocks) block.render(*this->window);
}

void Game::render()
{
  this->window->clear();
  this->player.render(*this->window);
  this->renderBlocks();
  this->window->display();
}

// Functions

void Game::run()
{
  while (this->window->isOpen())
  {
    this->update();
    this->render();
  }
}
