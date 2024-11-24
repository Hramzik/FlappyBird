
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"

//--------------------------------------------------

class LifeResolver: public Component {

  public:
    bool is_alive ();
    void kill ();

  private:
    bool is_alive_ = true;
};

//--------------------------------------------------
