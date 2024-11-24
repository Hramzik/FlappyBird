
//--------------------------------------------------

#include <iostream>

#include "TextureRenderer.h"
#include "src/Components/Transform/Transform.h"

//--------------------------------------------------

TextureRenderer::TextureRenderer (Texture& texture, Screen& screen):
    texture_ (texture),
    screen_  (screen) {}

Texture& TextureRenderer::get_texture () {

    return texture_;
}

void TextureRenderer::draw () {

    Vector2<double> coords = owner_->get_component<Transform> ()->get_position ();
    Vector2<int> pos ((int) coords.x, (int) coords.y);

    screen_.render (texture_, pos);
}

//--------------------------------------------------
