
//--------------------------------------------------

#include "CollisionManager.h"

//--------------------------------------------------

void CollisionManager::add_collider (Collider& collider) {

    colliders_.push_back (&collider);
}

void CollisionManager::act (double dt) {

    for (Collider* collider1 : colliders_) {
    for (Collider* collider2 : colliders_) {

        if (collider1 == collider2) continue;
        if (!collider1->check_collision (*collider2)) continue;
        collider1->on_collision_enter (*collider2);
        // будет вызвано когда 1 и 2 свапнутся
        //collider2->on_collision_enter (*collider1);
    }
    }
}

//--------------------------------------------------
