
//--------------------------------------------------

#pragma once

#include "src/Components/TextureRenderer/TextureRenderer.h"

//--------------------------------------------------

class HitboxRenderer: public TextureRenderer {

  public:
    HitboxRenderer (Texture& texture_, Camera& camera);
    void draw () override;
    void turn_off ();

  private:
    bool is_active_ = true;
};