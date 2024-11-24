
//--------------------------------------------------

#pragma once

#include "src/GameObject/GameObject.h"

//--------------------------------------------------

class Component {

  public:
    void set_owner (GameObject& owner);
    virtual void act  (double dt);
    virtual void draw ();

  protected:
    GameObject* owner_;
};

//--------------------------------------------------
