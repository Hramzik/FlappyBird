
//--------------------------------------------------

#include "BorderKillResolver.h"
#include "src/Components/Transform/Transform.h"
#include "src/Components/LifeResolver/LifeResolver.h"

//--------------------------------------------------

void BorderKillResolver::act (double dt) {

    if (!owner_) return;
    Transform*        tr   = owner_->get_component<Transform> ();
    LifeResolver*     life = owner_->get_component<LifeResolver> ();
    if (!tr || !life) return;

    //--------------------------------------------------

    if (tr->get_position ().y >= MIN_Y && tr->get_position ().y <= MAX_Y) return;
    life->kill ();
}

//--------------------------------------------------
