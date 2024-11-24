
//--------------------------------------------------

#pragma once

#include <iostream>
#include <map>
#include <string>
#include <memory>

#include "src/Texture/Texture.h"

//--------------------------------------------------

class TextureStorage {

  public:
    TextureStorage ();
    Texture& get_texture (const char* path);

  private:
    std::map<std::string, Texture*> textures_;
};

//--------------------------------------------------
