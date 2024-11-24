
//--------------------------------------------------

#include "PlayerController.h"
#include "src/Components/Rigidbody/Rigidbody.h"

//--------------------------------------------------

void PlayerController::act (double dt) {

    if (!is_key_pressed (JUMP_KEY)) { allowed_to_jump_ = true; return; }
    if (!allowed_to_jump_) return;

    //--------------------------------------------------

    jump ();
    allowed_to_jump_ = false;
}

void PlayerController::jump () {

    RigidBody* rb = owner_->get_component<RigidBody> ();
    Vector2<double> old_velocity = rb->get_velocity ();
    Vector2<double> new_velocity (old_velocity.x, JUMP_SPEED);
    owner_->get_component<RigidBody> ()->set_velocity (new_velocity);
}

//--------------------------------------------------
