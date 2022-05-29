#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "../Headers.h"

class TextureManager
{
  private:
    std::map<std::string, sf::Texture*> textures;

  public:
    // Constructor
    TextureManager(){};

    // Functions
    void addTexture(std::string textureName, std::string texturePath);
    sf::Texture* getTexture(std::string textureName);
};

#endif // TEXTUREMANAGER_H
