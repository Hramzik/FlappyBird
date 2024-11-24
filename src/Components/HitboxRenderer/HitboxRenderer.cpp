
//--------------------------------------------------

#include <iostream>

#include "HitboxRenderer.h"
#include "src/Components/Transform/Transform.h"
#include "src/Components/Collisions/Collider.h"

//--------------------------------------------------

HitboxRenderer::HitboxRenderer (Texture& texture, Camera& camera):
        TextureRenderer (texture, camera) {}

void HitboxRenderer::draw () {

    if (!is_active_) return;
    if (!owner_) return;

    Transform* owner_tr = owner_->get_component<Transform> ();
    if (!owner_tr) return;
    Vector2<double> owner_pos = owner_tr->get_position ();

    Collider* collider = owner_->get_component<Collider> ();
    if (!collider) return;

    //--------------------------------------------------

    for (const CollisionBox& box: collider->get_boxes ()) {

        Vector2<double> box_pos = owner_pos + box.get_offset ();
        camera_.render_view (box_pos, texture_);
    }
    //turn_off ();
}

void HitboxRenderer::turn_off () {

    is_active_ = false;
}

//--------------------------------------------------
