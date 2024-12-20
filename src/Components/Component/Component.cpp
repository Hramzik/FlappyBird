
//--------------------------------------------------

#include <iostream>

#include "Component.h"

//--------------------------------------------------

void Component::set_owner (GameObject& owner) {

    owner_ = &owner;
}

void Component::activate () {

    is_active_ = true;
}

void Component::deactivate () {

    is_active_ = false;
}

void Component::act  (double dt) {}
void Component::draw () {}

//--------------------------------------------------
