
//--------------------------------------------------

#include "Transform.h"

//--------------------------------------------------

Transform::Transform (Vector2<double> position):
        position_ (position) {}

Vector2<double> Transform::get_position () {

    return position_;
}

void Transform::set_position (Vector2<double> pos) {

    position_ = pos;
}

void Transform::move (Vector2<double> movement) {

    position_ += movement;
}

//--------------------------------------------------
