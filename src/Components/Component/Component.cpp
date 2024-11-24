
//--------------------------------------------------

#include "Component.h"

//--------------------------------------------------

void Component::set_owner (GameObject& owner) {

    owner_ = &owner;
}

void Component::act  (double dt) {}
void Component::draw () {}

//--------------------------------------------------
