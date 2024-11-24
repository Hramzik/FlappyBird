
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "src/Screen/Screen.h"

//--------------------------------------------------

class Camera: public Component {

  public:
    Camera (Screen& screen);
    void render_view (GameObject& object);

  private:
    Screen& screen_;
};