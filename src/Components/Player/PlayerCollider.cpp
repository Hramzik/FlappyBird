
//--------------------------------------------------

#include "PlayerCollider.h"
#include "src/Components/LifeResolver/LifeResolver.h"

//--------------------------------------------------

void PlayerCollider::on_collision_enter (Collider& other) {

    if (!owner_) return;
    LifeResolver* life_resolver = owner_->get_component<LifeResolver> ();
    if (!life_resolver) return;

    //--------------------------------------------------

    life_resolver->kill ();
}

//--------------------------------------------------
