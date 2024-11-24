
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "src/Vector2/Vector2.h"

//--------------------------------------------------

class FollowerLinker: public Component {

  public:
    FollowerLinker (GameObject& follower);
    void set_follower_offset (Vector2<double> offset);
    void set_follow_x (bool flag);
    void set_follow_y (bool flag);
    void act (double dt) override;

  private:
    GameObject& follower_;
    Vector2<double> follower_offset_ = 0;
    bool follow_x_ = true;
    bool follow_y_ = true;
};

//--------------------------------------------------
