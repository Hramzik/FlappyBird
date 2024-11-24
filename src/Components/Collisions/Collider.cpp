
//--------------------------------------------------

#include "Collider.h"
#include "src/Components/Transform/Transform.h"

//--------------------------------------------------

Collider::Collider ():
        boxes_ () {}

void Collider::add_box (const CollisionBox& box) {

    boxes_.push_back (box);
}

bool Collider::check_collision(const Collider& other) {

    if (!owner_ || !other.owner_) return false;
    Transform* my_tr =       owner_->get_component<Transform> ();
    Transform* his_tr = other.owner_->get_component<Transform> ();
    if (!my_tr || !his_tr) return false;

    //--------------------------------------------------

    for (const CollisionBox& my_relative_box  :       boxes_) {
    for (const CollisionBox& his_relative_box : other.boxes_) {

        CollisionBox my_box  = my_relative_box .move (my_tr ->get_position ());
        CollisionBox his_box = his_relative_box.move (his_tr->get_position ());
        if (my_box.check_collision (his_box)) return true;
    }}

    return false;
}

void Collider::on_collision_enter (Collider& other) {}

//--------------------------------------------------
