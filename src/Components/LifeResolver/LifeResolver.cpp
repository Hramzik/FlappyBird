
//--------------------------------------------------

#include <iostream>

#include "LifeResolver.h"

//--------------------------------------------------

bool LifeResolver::is_alive () {

    return is_alive_;
}

void LifeResolver::kill () {

    is_alive_ = false;
}

//--------------------------------------------------
