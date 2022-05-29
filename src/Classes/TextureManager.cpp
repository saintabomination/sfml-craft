#include "../Headers/TextureManager.h"

// Functions

void TextureManager::addTexture(std::string textureName, std::string texturePath)
{
  sf::Texture* texture = new sf::Texture();
  if (!texture->loadFromFile(texturePath))
  {
    std::cerr << "ERROR::TEXTUREMANAGER::CANT_LOAD_TEXTURE\n" << texturePath << '\n';
    return;
  }
  texture->setRepeated(true);
  this->textures.insert(std::pair<std::string, sf::Texture*>(textureName, texture));
}

sf::Texture* TextureManager::getTexture(std::string textureName)
{
  auto it = this->textures.find(name);
  if (it == this->textures.end()) {
    std::cerr << "ERROR::TEXTUREMANAGER::CANT_FIND_TEXTURE\n";
    return new sf::Texture();
  }
  return it->second;
}
