
//--------------------------------------------------

#pragma once

#include <vector>

#include "src/Vector2/Vector2.h"

//--------------------------------------------------

// изначально предполагалась возможность поворота
// поэтому box хранит все 4 вершины
class CollisionBox {

  public:
    CollisionBox ();
    CollisionBox (Vector2<double> offset, Vector2<double> size);
    Vector2<double> get_offset () const;
    CollisionBox move (Vector2<double> movement) const;
    bool check_collision(const CollisionBox& other) const;

    std::vector<Vector2<double>> get_axes () const;
    std::pair<double, double>    project (const Vector2<double>& axis) const;

  private:
    Vector2<double> vertex1_;
    Vector2<double> vertex2_;
    Vector2<double> vertex3_;
    Vector2<double> vertex4_;
};

//--------------------------------------------------
