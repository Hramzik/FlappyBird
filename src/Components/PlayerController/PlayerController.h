
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "Engine.h"

//--------------------------------------------------

class PlayerController: public Component {

  public:
    void act (double dt) override;
    void jump ();

  private:
    bool allowed_to_jump_ = true;

    static constexpr int    JUMP_KEY   = VK_SPACE;
    static constexpr double JUMP_SPEED = -550;

  public:
    static constexpr double DEFAULT_SPEED = 100;
};

//--------------------------------------------------
