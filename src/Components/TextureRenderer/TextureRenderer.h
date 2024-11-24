
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "src/Screen/Screen.h"

//--------------------------------------------------

class TextureRenderer: public Component {

  public:
    TextureRenderer (Texture& texture_, Screen& screen);
    Texture& get_texture ();
    void draw () override;

  private:
    Texture& texture_;
    Screen&  screen_;
};