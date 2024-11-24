
//--------------------------------------------------

#include "Camera.h"

#include "src/Components/TextureRenderer/TextureRenderer.h"
#include "src/Components/Transform/Transform.h"

//--------------------------------------------------

Camera::Camera (Screen& screen):
        screen_ (screen) {}

void Camera::render_view (Vector2<double> object_pos, Texture& object_texture) {

    Vector2<double> camera_pos (0);
    if (owner_ && owner_->get_component<Transform> ()) camera_pos = owner_->get_component<Transform> ()->get_position ();

    //--------------------------------------------------

    Vector2<double> relative_pos = object_pos - camera_pos;
    Vector2<int> screen_pos ((int) relative_pos.x, (int) relative_pos.y);

    screen_.render (object_texture, screen_pos);
}

//--------------------------------------------------
