
//--------------------------------------------------

#include "FollowerLinker.h"

#include "src/Components/Transform/Transform.h"

//--------------------------------------------------

FollowerLinker::FollowerLinker (GameObject& follower):
        follower_ (follower) {}

void FollowerLinker::act (double dt) {

    if (!owner_) return;
    Transform* follower_tr = follower_.get_component<Transform> ();
    Transform* transform   = owner_->get_component<Transform> ();
    if (!follower_tr || !transform) return;

    //--------------------------------------------------

    Vector2<double> my_pos  =   transform->get_position ();
    Vector2<double> new_pos = follower_tr->get_position ();

    if (follow_x_) new_pos.x = my_pos.x + follower_offset_.x;
    if (follow_y_) new_pos.y = my_pos.y + follower_offset_.y;

    follower_tr->set_position (new_pos);
}

void FollowerLinker::set_follower_offset (Vector2<double> offset) {

    follower_offset_ = offset;
}

void FollowerLinker::set_follow_x (bool flag) {

    follow_x_ = flag;
}

void FollowerLinker::set_follow_y (bool flag) {

    follow_y_ = flag;
}

//--------------------------------------------------
