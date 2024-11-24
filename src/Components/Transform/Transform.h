
//--------------------------------------------------

#pragma once

#include "src/Components/Component/Component.h"
#include "src/Vector2/Vector2.h"

//--------------------------------------------------

class Transform: public Component {

  public:
    Transform (Vector2<double> position);
    Vector2<double> get_position ();
    void            set_position (Vector2<double> pos);
    void move (Vector2<double> movement);

  private:
    Vector2<double> position_;
};

//--------------------------------------------------
