
//--------------------------------------------------

#pragma once

#include <vector>

#include "src/Components/Component/Component.h"
#include "Collider.h"

//--------------------------------------------------

class CollisionManager: public Component {

  public:
    void observe (std::vector<GameObject*>& objects);
    void act (double dt) override;

  private:
    std::vector<GameObject*>* objects_ = nullptr;
};

//--------------------------------------------------
