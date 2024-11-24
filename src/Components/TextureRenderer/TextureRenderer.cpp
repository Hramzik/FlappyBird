
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

    if (!owner_) return;
    camera_.render_view (*owner_);
}

//--------------------------------------------------
