
//--------------------------------------------------

#pragma once

#include "Buffer.h"
#include "src/Texture/Texture.h"
#include "src/Vector2/Vector2.h"

//--------------------------------------------------

class Screen {

  public:
    Screen (Buffer& buffer);
    void render (Texture& texture, Vector2<int> pos);
    void draw (Vector2<int> pixel, uint32_t color);

  private:
    Buffer& buffer_;
};

//--------------------------------------------------
