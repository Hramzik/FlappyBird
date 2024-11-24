
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "Engine.h"

//--------------------------------------------------

class BorderKillResolver: public Component {

  public:
    void act (double dt) override;

  private:
    static constexpr double MIN_Y = 0;
    static constexpr double MAX_Y = SCREEN_HEIGHT - 90;
};

//--------------------------------------------------
