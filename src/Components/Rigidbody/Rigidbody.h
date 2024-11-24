
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "src/Vector2/Vector2.h"

//--------------------------------------------------

class RigidBody: public Component {

  public:
    RigidBody ();
    RigidBody (Vector2<double> velocity);
    void act (double dt) override;
    Vector2<double> get_velocity ();
    void            set_velocity (Vector2<double> velocity);

  private:
    Vector2<double> velocity_;

  private:
    static constexpr double FREEFALL_ACCELERATION = 2200;
};