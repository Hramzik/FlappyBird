
//--------------------------------------------------

#pragma once

#include <vector>

#include "src/Components/Component/Component.h"
#include "CollisionBox.h"

//--------------------------------------------------

class Collider: public Component {

  public:
    Collider ();
    ~Collider () override = default;
    std::vector<CollisionBox>& get_boxes ();
    void                       add_box   (const CollisionBox& box);
    bool check_collision (const Collider& other);
    virtual void on_collision_enter (Collider& other);

  private:
    std::vector<CollisionBox> boxes_;
};

//--------------------------------------------------
