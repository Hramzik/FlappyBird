
//--------------------------------------------------

#pragma once

#include <vector>

#include "src/Components/Component/Component.h"
#include "Collider.h"

//--------------------------------------------------

class CollisionManager: public Component {

  public:
    void add_collider (Collider& collider);
    void act (double dt) override;

  private:
    std::vector<Collider*> colliders_;
};
//--------------------------------------------------
