
//--------------------------------------------------

#include "CollisionBox.h"

//--------------------------------------------------

CollisionBox::CollisionBox ():
    CollisionBox (0, 0) {}

CollisionBox::CollisionBox (Vector2<double> offset, Vector2<double> size):
        vertex1_ (),
        vertex2_ (),
        vertex3_ (),
        vertex4_ ()
{
    vertex1_ = Vector2<double> (offset.x,          offset.y);
    vertex2_ = Vector2<double> (offset.x + size.x, offset.y);
    vertex3_ = Vector2<double> (offset.x,          offset.y + size.y);
    vertex4_ = Vector2<double> (offset.x + size.x, offset.y + size.y);
}

Vector2<double> CollisionBox::get_offset () const {

    return vertex1_;
}

CollisionBox CollisionBox::move (Vector2<double> movement) const {

    CollisionBox result;
    result.vertex1_ = vertex1_ + movement;
    result.vertex2_ = vertex2_ + movement;
    result.vertex3_ = vertex3_ + movement;
    result.vertex4_ = vertex4_ + movement;

    return result;
}

bool CollisionBox::check_collision (const CollisionBox& other) const {

    std::vector<Vector2<double>> axes       =       get_axes();
    std::vector<Vector2<double>> other_axes = other.get_axes();
    axes.insert(axes.end (), other_axes.begin (), other_axes.end ());

    //--------------------------------------------------

    for (const auto& axis : axes) {

        std::pair<double, double> p1 =       project (axis);
        std::pair<double, double> p2 = other.project (axis);
        if (p1.second < p2.first || p2.second < p1.first) return false; // separating axis
    }

    return true;
}

std::vector<Vector2<double>> CollisionBox::get_axes () const {

    std::vector<Vector2<double>> axes;
    axes.push_back ((vertex2_ - vertex1_).normalize ());
    axes.push_back ((vertex3_ - vertex2_).normalize ());

    return axes;
}

std::pair<double, double> CollisionBox::project (const Vector2<double>& axis) const {

    double min_p = scalar_product (vertex1_, axis);
    double max_p = min_p;

    double p = scalar_product (vertex2_, axis);
    if (p < min_p) min_p = p;
    if (p > max_p) max_p = p;

    p = scalar_product (vertex3_, axis);
    if (p < min_p) min_p = p;
    if (p > max_p) max_p = p;

    p = scalar_product (vertex4_, axis);
    if (p < min_p) min_p = p;
    if (p > max_p) max_p = p;

    return std::make_pair(min_p, max_p);
}



//--------------------------------------------------
