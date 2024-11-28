
//--------------------------------------------------

#pragma once

#include <vector>

//--------------------------------------------------

class Component;

//--------------------------------------------------

class GameObject {

  public:
    GameObject  ();
    ~GameObject ();

    void act (double dt);
    void draw ();

    template <typename T>
    T* get_component ();
    void add_component (Component& component);

  private:
    std::vector<Component*> components_;
};

//--------------------------------------------------

#include "GameObject.inl"

//--------------------------------------------------
