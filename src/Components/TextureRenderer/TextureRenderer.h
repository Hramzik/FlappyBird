
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "src/Components/Camera/Camera.h"
#include "src/Screen/Screen.h"

//--------------------------------------------------

class TextureRenderer: public Component {

  public:
    TextureRenderer  (Texture& texture_, Camera& camera);
    ~TextureRenderer () override;
    Texture& get_texture ();
    void draw () override;

  protected:
    Texture& texture_;
    Camera&  camera_;
};

//--------------------------------------------------
