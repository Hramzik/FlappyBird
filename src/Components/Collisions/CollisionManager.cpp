
//--------------------------------------------------

#include "CollisionManager.h"

//--------------------------------------------------

void CollisionManager::observe (std::vector<GameObject*>& objects) {

    objects_ = &objects;
}

void CollisionManager::act (double dt) {

    if (!objects_) return;

    //--------------------------------------------------

    for (GameObject* obj1 : *objects_) {
    for (GameObject* obj2 : *objects_) {

        if (obj1 == obj2) continue;
        Collider* collider1 = obj1->get_component<Collider> ();
        Collider* collider2 = obj2->get_component<Collider> ();
        if (!collider1 || !collider2) continue;
        if (collider1 == collider2) continue;

        if (!collider1->check_collision (*collider2)) continue;
        collider1->on_collision_enter (*collider2);
        // будет вызвано когда 1 и 2 свапнутся
        // collider2->on_collision_enter (*collider1);
    }
    }
}

//--------------------------------------------------
