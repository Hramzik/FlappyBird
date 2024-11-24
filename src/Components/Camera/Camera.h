
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "src/Screen/Screen.h"

//--------------------------------------------------

class Camera: public Component {

  public:
    Camera (Screen& screen);
    void render_view (Vector2<double> object_pos, Texture& object_texture);

  private:
    Screen& screen_;
};

//--------------------------------------------------
