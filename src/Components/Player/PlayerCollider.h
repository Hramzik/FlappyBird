
//--------------------------------------------------

#pragma once

#include "src/Components/Collisions/Collider.h"

//--------------------------------------------------

class PlayerCollider: public Collider {

  public:
    void on_collision_enter (Collider& other) override;
};
//--------------------------------------------------
