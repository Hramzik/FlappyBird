
//--------------------------------------------------

#include <iostream>

#include "GameObject.h"
#include "src/Components/Component/Component.h"

//--------------------------------------------------

GameObject::GameObject ():
        components_ () {}

GameObject::~GameObject () {

    for (Component* comp : components_) {

        delete comp;
    }
}

void GameObject::act (double dt) {

    for (Component* comp : components_) {

        comp->act (dt);
    }
}

void GameObject::draw () {

    for (Component* comp : components_) {

        comp->draw ();
    }
}

void GameObject::add_component (Component& component) {

    component.set_owner (*this);
    components_.push_back (&component);
}

//--------------------------------------------------
