
//--------------------------------------------------

#pragma once

#include "src/GameObject/GameObject.h"

//--------------------------------------------------

class Component {

  public:
    void set_owner (GameObject& owner);
    void activate   ();
    void deactivate ();
    virtual void act  (double dt);
    virtual void draw ();

  protected:
    GameObject* owner_;
    bool is_active_ = true;
};

//--------------------------------------------------
