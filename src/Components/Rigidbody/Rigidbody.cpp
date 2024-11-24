
//--------------------------------------------------

#include "Rigidbody.h"
#include "src/Components/Transform/Transform.h"

//--------------------------------------------------

RigidBody::RigidBody ():
        RigidBody (0) {}

RigidBody::RigidBody (Vector2<double> velocity):
        velocity_ (velocity) {}

void RigidBody::act (double dt) {

    if (!is_active_) return;

    //--------------------------------------------------

    owner_->get_component<Transform> ()->move (velocity_ * dt);
    velocity_.y += FREEFALL_ACCELERATION * dt;
}

Vector2<double> RigidBody::get_velocity () {

    return velocity_;
}

void RigidBody::set_velocity (Vector2<double> velocity) {

    velocity_ = velocity;
}

//--------------------------------------------------
