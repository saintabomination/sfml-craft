#include "../Headers/Game.h"

// Testing
sf::RectangleShape testingShape;
sf::RectangleShape testingShapeTwo;
sf::RectangleShape testingShapeThree;
sf::RectangleShape testingShapeFour;
sf::Vector2f rayPoint;
sf::Vector2i mousePos;
sf::Vector2f rayDirection;
sf::Vertex line[2];

// Initialisers

void Game::initWindow()
{
  std::string windowTitle {"SFML"};
  unsigned int windowWidth {640};
  unsigned int windowHeight {480};
  unsigned int windowFPSLimit {60};
  bool windowVSyncEnabled {false};

  std::ifstream configFile("src/Config/Window.ini");
  if (!configFile.is_open())
  {
    std::cout << "ERROR::GAME::CANT_LOAD_WINDOW_CONFIG" << std::endl;
  }
  else
  {
    configFile >> windowTitle;
    configFile >> windowWidth >> windowHeight;
    configFile >> windowFPSLimit;
    configFile >> windowVSyncEnabled;
  }

  this->window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowTitle);
  this->window->setFramerateLimit(windowFPSLimit);
  this->window->setVerticalSyncEnabled(windowVSyncEnabled);
  this->view.setSize(sf::Vector2f((float)windowWidth, (float)windowHeight));
}

void Game::initTextures()
{
  this->textureManager.addTexture("player", "src/Assets/Textures/stew.png");
  this->textureManager.addTexture("grass", "src/Assets/Textures/grass.png");
}

void Game::initPlayer()
{
  this->player.setTexture(this->textureManager.getTexture("player"));
  this->player.setSpeed(160.f);
  this->player.setGravityFactor(120.f);
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

  // Testing

  testingShape.setSize(sf::Vector2f(32.f, 32.f));
  testingShape.setPosition(sf::Vector2f(64.f, 64.f));

  testingShapeTwo.setSize(sf::Vector2f(64.f, 32.f));
  testingShapeTwo.setFillColor(sf::Color::Yellow);

  testingShapeThree.setSize(sf::Vector2f(32.f, 32.f));
  testingShapeThree.setPosition(sf::Vector2f(160.f, 64.f));

  testingShapeFour.setSize(sf::Vector2f(32.f, 32.f));
  testingShapeFour.setPosition(sf::Vector2f(256.f, 64.f));
}

Game::~Game()
{
  delete this->window;
}

// Accessors

const float Game::getDt() const
{
  return this->dtTimer;
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

void Game::updateClocks()
{
  this->dtTimer = this->dtClock.restart().asSeconds();
}

void Game::updateKeys()
{
  bool wasKeyPressed = false;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
  {
    this->player.setVelocityX(-1.f);
    wasKeyPressed = true;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
  {
    this->player.setVelocityX(1.f);
    wasKeyPressed = true;
  }

  if (!wasKeyPressed) this->player.setVelocityX(0.f);
}

void Game::updateCollisions()
{
  sf::Vector2f cp, cn;
  float ct;

  for (Block block : this->blocks)
  {
    if (Collisions::dynamicRayVsRect(this->player.getBounds(), block.getBounds(), this->player.getVelocity(), cp, cn, ct))
    {
      this->player.setVelocity(sf::Vector2f(0.f, 0.f));
    }
  }
}

void Game::updatePlayer()
{
  this->player.update();
}

void Game::updateView()
{
  this->view.setCenter(sf::Vector2f(
    this->player.getBounds().left + this->player.getBounds().width / 2,
    this->player.getBounds().top + this->player.getBounds().height / 2
  ));
  this->window->setView(this->view);
}

void Game::update()
{
  this->updateSFMLEvents();
  this->updateClocks();
  this->updateKeys();
  this->updateCollisions();
  this->updatePlayer();
  this->updateView();

  // Testing Collisions

  sf::Vector2i mousePos = sf::Mouse::getPosition(*this->window);
  sf::Vector2f worldPos = this->window->mapPixelToCoords(mousePos);

  testingShapeTwo.setPosition(worldPos);

  if (Collisions::pointVsRect(worldPos, testingShape.getGlobalBounds()))
  {
    testingShape.setFillColor(sf::Color::Red);
  }
  else
  {
    testingShape.setFillColor(sf::Color::Blue);
  }

  if (Collisions::rectVsRect(testingShapeTwo.getGlobalBounds(), testingShapeThree.getGlobalBounds()))
  {
    testingShapeThree.setFillColor(sf::Color::Green);
  }
  else
  {
    testingShapeThree.setFillColor(sf::Color::Magenta);
  }

  // Testing: Drawing a ray

  sf::Vector2f viewCenter = this->window->getView().getCenter();
  sf::Vector2f halfExtents = this->window->getView().getSize() / 2.0f;

  rayPoint = sf::Vector2f(
    this->player.getBounds().left + 16.f,
    this->player.getBounds().top + 16.f
  );

  mousePos = sf::Mouse::getPosition(*this->window);
  sf::Vector2f newMousePos = sf::Vector2f(mousePos.x + this->player.getBounds().left, mousePos.y + this->player.getBounds().top);
  newMousePos.x -= halfExtents.x - 16.f;
  newMousePos.y -= halfExtents.y - 16.f;

  rayDirection = newMousePos;
  rayDirection.x -= rayPoint.x;
  rayDirection.y -= rayPoint.y;

  line[0].position = sf::Vector2f(newMousePos);
  line[0].color = sf::Color::Red;
  line[1].position = rayPoint;
  line[1].color = sf::Color::Red;

  sf::Vector2f cp, cn;
  float t;

  if (Collisions::rayVsRect(rayPoint, rayDirection, testingShapeFour.getGlobalBounds(), cp, cn, t) && t <= 1.f)
  {
    testingShapeFour.setFillColor(sf::Color::White);
  }
  else
  {
    testingShapeFour.setFillColor(sf::Color::Cyan);
  }
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
  this->window->draw(testingShape);
  this->window->draw(testingShapeTwo);
  this->window->draw(testingShapeThree);
  this->window->draw(testingShapeFour);
  this->window->draw(line, 2, sf::Lines);
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
