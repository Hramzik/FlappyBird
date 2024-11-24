
//--------------------------------------------------

#include <iostream>

#include "TextureRenderer.h"
#include "src/Components/Transform/Transform.h"

//--------------------------------------------------

TextureRenderer::TextureRenderer (Texture& texture, Camera& camera):
    texture_ (texture),
    camera_  (camera) {}

Texture& TextureRenderer::get_texture () {

    return texture_;
}

void TextureRenderer::draw () {

    if (!is_active_) return;
    if (!owner_) return;
    Transform* owner_tr = owner_->get_component<Transform> ();
    if (!owner_tr) return;

    //--------------------------------------------------

    camera_.render_view (owner_tr->get_position (), texture_);
}

//--------------------------------------------------
