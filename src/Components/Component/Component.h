
//--------------------------------------------------

#pragma once

#include "src/GameObject/GameObject.h"

//--------------------------------------------------

class Component {

  public:
    virtual ~Component () = default;
    void set_owner (GameObject& owner);
    void activate   ();
    void deactivate ();
    virtual void act  (double dt);
    virtual void draw ();

  protected:
    GameObject* owner_ = nullptr;
    bool is_active_ = true;
};

//--------------------------------------------------
