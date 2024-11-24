
//--------------------------------------------------

#include <iostream>

#include "TubeDespawner.h"
#include "src/Components/Transform/Transform.h"
#include "src/Components/Tube/Tube.h"

//--------------------------------------------------

TubeDespawner::TubeDespawner (GameObject& anker, std::vector<GameObject*>& tubes):
        anker_   (anker),
        tubes_   (tubes) {}


void TubeDespawner::act (double dt) {

    for (auto it = tubes_.begin (); it != tubes_.end ();) {

        GameObject* obj = *it;
        Tube* tube = obj->get_component<Tube> ();
        if (!tube) { ++it; continue; }

        Transform* tr       = obj  ->get_component<Transform> ();
        Transform* anker_tr = anker_.get_component<Transform> ();
        if (!tr || !anker_tr) { ++it; continue; }
        if (tr->get_position ().x >= anker_tr->get_position ().x - DESPAWN_RADIUS) { ++it; continue; }

        //--------------------------------------------------
        delete tube;
        it = tubes_.erase(it);
    }
}

//--------------------------------------------------
